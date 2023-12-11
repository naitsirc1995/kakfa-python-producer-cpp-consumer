#include<iostream>
#include<unistd.h>
#include<kafka/KafkaConsumer.h>

#include<cstdlib>
#include<signal.h>
#include<string>

using namespace std;

std::atomic_bool running = {true};


void stopRunning(int sig){
    if (sig != SIGINT) return;

    if (running){
        running = false;
    } else {
        signal(SIGINT,SIG_IGN);
    }
}



int main(){

    using namespace kafka;
    using namespace kafka::clients::consumer;

    signal(SIGINT,stopRunning);

    const std::string KAFKA_SERVER = getenv("KAFKA_SERVER");
    const std::string KAFKA_PORT = getenv("KAFKA_PORT");
    const std::string broker = KAFKA_SERVER+":"+KAFKA_PORT;
    const Topic TOPIC = getenv("KAFKA_TOPIC_NAME");

    const Properties props({{"bootstrap.servers", {broker}}});

    KafkaConsumer consumer(props);

    consumer.subscribe({TOPIC});

    while (running) {
        // Poll messages from Kafka brokers
        auto records = consumer.poll(std::chrono::milliseconds(100));

        for (const auto& record: records) {
            if (!record.error()) {
                std::cout << "Got a new message..." << std::endl;
                std::cout << "    Topic    : " << record.topic() << std::endl;
                std::cout << "    Partition: " << record.partition() << std::endl;
                std::cout << "    Offset   : " << record.offset() << std::endl;
                std::cout << "    Timestamp: " << record.timestamp().toString() << std::endl;
                std::cout << "    Headers  : " << toString(record.headers()) << std::endl;
                std::cout << "    Key   [" << record.key().toString() << "]" << std::endl;
                std::cout << "    Value [" << record.value().toString() << "]" << std::endl;
            } else {
                std::cerr << record.toString() << std::endl;
            }
        }
    }


    consumer.close();


    return 0;
}
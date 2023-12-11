# kakfa python producer cpp consumer

In the dynamic realm of modern software development, seamless communication between diverse components is paramount. This project embarks on a journey to create a robust and efficient data pipeline using Apache Kafka, a distributed streaming platform that has become the backbone of many real-time applications.

At its core, this project is an elegant synergy of Python and C++, orchestrating a real-time data exchange through Kafka. The producer, crafted with the versatility and simplicity of Python, takes center stage in generating data that propels the heartbeat of our system. On the receiving end, a stalwart C++ consumer awaits, ready to process and derive insights from the incoming stream.



## How to use

### Using Docker Compose 
You will need Docker installed to follow the next steps. To create and run the image use the following command:

```bash
> docker-compose up --build
```



### API

- Send Message

Send message to Kafka, below is an example request:
```json
POST http://localhost:8000/producer
Accept: application/json
Content-Type: application/json
Body:
{
    "name": "value",
    "description": "value",
}
```


- Health check

Checks if the app is available.
```json
GET http://localhost:8000/
Accept: application/json
Content-Type: application/json
```
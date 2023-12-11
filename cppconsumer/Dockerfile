FROM ubuntu:22.04

ARG LIBRDKAFKA_VERSION=2.1.1

RUN apt-get update \
    && apt-get install -y \
        build-essential \
        cmake \
        curl \
    && curl -L https://github.com/confluentinc/librdkafka/archive/refs/tags/v${LIBRDKAFKA_VERSION}.tar.gz | tar -xz \
    && cd librdkafka-${LIBRDKAFKA_VERSION} \
    && ./configure \
    && make \
    && make install \
    && ldconfig \
    && cd .. \
    && rm -rf librdkafka-${LIBRDKAFKA_VERSION}



RUN mkdir modern-cpp-kafka \
    && curl -L https://github.com/morganstanley/modern-cpp-kafka/archive/refs/tags/v2023.03.07.tar.gz | tar -xz --strip-components=1 -C modern-cpp-kafka \
    && mv modern-cpp-kafka/include/kafka /usr/local/include \
    && rm -rf modern-cpp-kafka


# Copy source code
COPY . .

# Compile code
RUN mkdir build && cd build && cmake -S .. -B . \
    && make && cd ..

# Run the application
CMD ["build/main"]
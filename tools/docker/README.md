# ESP-IDF LDC Docker Image

[Original Doc](https://github.com/espressif/esp-idf/tree/master/tools/docker)

## Usage

```bash
docker run --rm -v $PWD:/project -w /project espressif/idf:latest idf.py build
```
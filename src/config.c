#include "stm32l1xx.h"

#define CONFIG_OFFSET 0x0800

// define addresses
#define ALT_FONT 0x0000 // 255 double bytes
#define TIME_FORMAT 0x0010 // 30 bytes (+NULL) eg. hh-mm-ss_DD-dd-mm-yy

void* getConfigPointer(uint32_t configId) {
  return CONFIG_OFFSET + configId;
}

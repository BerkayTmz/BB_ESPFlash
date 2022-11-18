#include "ESPFlashString.h"

ESPFlashString::ESPFlashString(const char* fileName, String defaultString)
{
  this->defaultString = defaultString;
  this->espFlash.setFileName(fileName);
  if(!SPIFFS.exists(fileName))
  {
    set(this->defaultString);
  }
}

ESPFlashString::ESPFlashString(const char* fileName, const char* defaultString)
{
  this->defaultString = defaultString;
  this->espFlash.setFileName(fileName);
  if(!SPIFFS.exists(fileName))
  {
    set(this->defaultString);
  }
}

void ESPFlashString::set(String string)
{
  espFlash.setElements(string.c_str(), string.length()+1);
}

void ESPFlashString::set(const char* string)
{
  espFlash.setElements(string, strlen(string)+1);
}

void ESPFlashString::reset(void)
{
  set(this->defaultString);
  return;
}

String ESPFlashString::get(void)
{
  char string[espFlash.length()];
  espFlash.getFrontElements(string, espFlash.length());
  return String(string);
}




#include <memxor.h>
#include <aes192_dec.h>
#include <aes_keyschedule.h>
#include <aes_types.h>
#include <aes_dec.h>
#include <bcal_aes192.h>
#include <aes256_enc.h>
#include <aes_invsbox.h>
#include <aes192_enc.h>
#include <aes256_dec.h>
#include <bcal-ofb.h>
#include <gf256mul.h>
#include <aes_enc.h>
#include <bcal_aes256.h>
#include <bcal-basic.h>
#include <bcal_aes128.h>
#include <keysize_descriptor.h>
#include <bcal-cmac.h>
#include <blockcipher_descriptor.h>
#include <aes128_enc.h>
#include <aes128_dec.h>
#include <aes_sbox.h>
#include <bcal-cbc.h>
#include <AESLib.h>
#include <aes.h>
#include <SoftwareSerial.h>
SoftwareSerial espSerial(5, 6);
char data[] = "0123456789012345";
uint8_t key[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
void setup()
{
  Serial.begin(115200);
  espSerial.begin(115200);
  delay(2000);
}
void loop()
{
  String my_string = "";
  aes128_enc_single(key, data);
  Serial.println("ENC: ");
  for (int index = 0; index < sizeof(data) / sizeof(char); ++index)
  {
    my_string += static_cast<int>(data[index]);
  }
  Serial.println(my_string);
  aes128_dec_single(key, data);
  Serial.println("DEC: ");
  for (int index = 0; index < sizeof(data) / sizeof(char); ++index)
  {
    Serial.print(data[index]);

  }
  Serial.println();
  delay(1000);
}

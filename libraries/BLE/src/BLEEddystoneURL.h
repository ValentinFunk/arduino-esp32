/*
 * BLEEddystoneURL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: pcbreflux
 */

#ifndef _BLEEddystoneURL_H_
#define _BLEEddystoneURL_H_
#include "soc/soc_caps.h"
#if SOC_BLE_SUPPORTED

#include "BLEUUID.h"

#define EDDYSTONE_URL_FRAME_TYPE 0x10

/**
 * @brief Representation of a beacon.
 * See:
 * * https://github.com/google/eddystone
 */
class BLEEddystoneURL {
public:
	BLEEddystoneURL();
	std::string getData();
	BLEUUID	 getUUID();
	int8_t	  getPower();
	std::string getURL();
	std::string getDecodedURL();
	void		setData(std::string data);
	void		setUUID(BLEUUID l_uuid);
	void		setPower(int8_t advertisedTxPower);
	void		setURL(std::string url);

private:
	uint16_t beaconUUID;
	uint8_t  lengthURL;
	struct {
		uint8_t frameType;
		int8_t  advertisedTxPower;
		uint8_t url[18];  // 18 bytes: 1 byte for URL scheme + up to 17 bytes of URL
	} __attribute__((packed)) m_eddystoneData;

}; // BLEEddystoneURL

#endif /* SOC_BLE_SUPPORTED */
#endif /* _BLEEddystoneURL_H_ */

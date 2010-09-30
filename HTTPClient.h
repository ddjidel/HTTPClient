/*
 * HTTPClient
 * HTTPClient.h
 *
 *  http://interactive-matter.org/
 *
 *  This file is part of HTTPClient.
 *
 *  HTTPClient is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  HTTPClient is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with HTTPClient.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: 18.09.2010
 *      Author: marcus
 */

#ifndef HTTPCLIENT_H_
#define HTTPCLIENT_H_

#include <inttypes.h>
#include "Client.h"

class HTTPClient: private Client {
private:
  char* hostName;
  uint8_t hostIp;

  FILE* openClientFile();
  static int clientWrite(char byte, FILE* stream);
  static int clientRead(FILE* stream);
  FILE* uriEncodeStream(FILE* stream);
  static int uriEncodedWrite(char byte, FILE* stream);
  static int uriEncodedRead(FILE* stream);
  int uriEncodedStringLength(char* string);
public:
  HTTPClient(char* host, uint8_t* ip, uint16_t port);
  FILE* getURI(char* uri);
  FILE* getURI(char* uri, char* headers);
  FILE* postURI(char* uri,char* data);
  static void closeStream(FILE* stream);
};


#endif /* HTTPCLIENT_H_ */

#pragma region ヘッダー
#define _CRT_SECURE_NO_WARNINGS

#ifdef _____MY_DEBUG_____
#define VS_ENDPAUSE()	(system("pause"))
#else
#define VS_ENDPAUSE()
#endif

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long long int64;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
#define int int64

#ifndef INT8_MIN
#define INT8_MIN	(-127)
#endif
#ifndef INT8_MAX
#define INT8_MAX	( 128)
#endif
#ifndef UINT8_MAX
#define UINT8_MAX	( 255)
#endif
#ifndef INT16_MIN
#define INT16_MIN	(-32768)
#endif
#ifndef INT16_MAX
#define INT16_MAX	( 32767)
#endif
#ifndef UINT16_MAX
#define UINT16_MAX	( 65535)
#endif
#ifndef INT32_MIN
#define INT32_MIN	(-2147483648)	// -2 * 10^9
#endif
#ifndef INT32_MAX
#define INT32_MAX	( 2147483647)	//  2 * 10^9
#endif
#ifndef UINT32_MAX
#define UINT32_MAX	( 4294967295)	//  4 * 10^9
#endif
#ifndef INT64_MIN
#define INT64_MIN	(-9223372036854775808)	// -9 * 10^18
#endif
#ifndef INT64_MAX
#define INT64_MAX	( 9223372036854775807)	//  9 * 10^18
#endif
#ifndef UINT64_MAX
#define UINT64_MAX	( 18446744073709551615)	// 18 * 10^18
#endif

void func(void);
#pragma endregion

int32 main(void)
{
	func();
	VS_ENDPAUSE();
	return 0;
}


void func(void)
{
	int r, g, b;
	cin >> r >> g >> b;
	int val = r*100 + g*10 + b;
	if(val % 4 == 0){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return;
}



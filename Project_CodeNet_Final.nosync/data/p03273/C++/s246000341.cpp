#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

typedef char                SINT8;
typedef unsigned char       UINT8;
typedef short               SINT16;
typedef unsigned short      UINT16;
typedef int                 SINT32;
typedef unsigned int        UINT32;
typedef long long           SINT64;
typedef unsigned long long  UINT64;
typedef double              DOUBLE;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;

int main() {

	SINT32 H,W;
	cin >>H>>W;
	SINT8 N[100][100];

	for (SINT32 i = 0; i < 100; i++) {
		for (SINT32 j = 0; j < 100; j++) {
			N[i][j] = 'A';
		}
	}

	for (SINT32 i = 0; i < H; i++) {
		for (SINT32 j = 0; j < W; j++) {
			cin >> N[i][j];
		}
	}

	for (SINT32 i = 0; i < H; i++) {
		SINT32 BUF = 0;
		for (SINT32 j = 0; j < W; j++) {
			if (N[i][j] == '#') {
				BUF = 1;
				break;
			}
		}
		if (BUF == 0) {
			for (SINT32 j = 0; j < W; j++) {
				N[i][j] = 'A';
			}
		}
	}

	for (SINT32 i = 0; i < W; i++) {
		SINT32 BUF = 0;
		for (SINT32 j = 0; j < H; j++) {
			if (N[j][i] == '#') {
				BUF = 1;
				break;
			}
		}
		if (BUF == 0) {
			for (SINT32 j = 0; j < H; j++) {
				N[j][i] = 'A';
			}
		}
	}




	for (SINT32 i = 0; i < H; i++) {
		SINT32 BUF = 0;
		for (SINT32 j = 0; j < W; j++) {
			
			if (N[i][j] == '#') {
				cout << '#';
				BUF = 1;
			} else if (N[i][j] == '.') {
				cout << '.';
				BUF = 1;
			}
		}
		if (BUF == 1) {
			cout << endl;
		}

	}

	
	return 0;
}

//	sort(DATA.begin(),DATA.end());
//	sort(DATA.begin(),DATA.end(),std::greater<SINT32>());
//	__gcd(ANS,DATA[i]);

/*
	SINT32 M = 3;
	vector<pair<SINT32,SINT32>> DATA2(M);
	for (SINT32 i = 0; i < M; i++) {
		cin >> DATA2[i].first;
		cin >> DATA2[i].second;
	}
	sort(DATA2.begin(),DATA2.end());
	cout << DATA2[0].first << endl;
	cout << DATA2[0].second << endl;
*/

//		APOSI = lower_bound(ADATA.begin(),ADATA.end(),QDATA[i]) - ADATA.begin();
//		BPOSI = lower_bound(BDATA.begin(),BDATA.end(),QDATA[i]) - BDATA.begin();
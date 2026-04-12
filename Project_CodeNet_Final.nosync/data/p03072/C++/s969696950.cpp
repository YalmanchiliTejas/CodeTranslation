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

	SINT32 N = 0;
	SINT32 M = 0;
	SINT32 ANS = 0;

	cin >> N;

	vector<SINT32> DATA(N);
	
	for (SINT32 i = 0; i < N; i++) {
		cin >> DATA[i];
		if (DATA[i] >= M) {
			ANS++;
		}
		M = MAX(M,DATA[i]);
	}

	cout << ANS << endl;
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
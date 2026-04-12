#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

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
#define rep(i,a,b) for(int (i)=int(a);(i)<int(b);(i)++)

#define INF 1000000001
#define MOD 1000000007
#define INF64 1000000000000000001

#define F first
#define S second

#define Pii pair<SINT32,SINT32>
#define Pll pair<SINT64,SINT64>


using namespace std;

int main() {

	SINT32 X,Y,Z;
	SINT32 cnt = 0;
	cin >> X>>Y>>Z;
	X = X-Z;
	
	while (1) {
		X -= Y+Z;
		if (X < 0) {
			break;
		}
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}

//	sort(DATA.begin(),DATA.end());
//	sort(DATA.begin(),DATA.end(),std::greater<SINT32>());
//	__gcd(ANS,DATA[i]);

//	// DATA.emplace_back(BUF);	//後ろに追加

//  DATA.erase(std::unique(DATA.begin(), DATA.end()), DATA.end());	//ソート後に使用

//	DATA.insert(DATA.begin() + X, 0);	//X番目の要素に0を挿入


//	vector<vector<SINT32>> DP(N,vector<SINT32>(3));	//2次元配列

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

// 	vector<pair<int,pair<int,int>>> DATA(M);
//	cin >> DATA[i].first;
//	cin >> DATA[i].second.first;
//	cin >> DATA[i].second.second;


//		APOSI = lower_bound(ADATA.begin(),ADATA.end(),QDATA[i]) - ADATA.begin();	//key以上を探す
//		BPOSI = lower_bound(BDATA.begin(),BDATA.end(),QDATA[i]) - BDATA.begin();


/* 文字列回転
	string N;
	cin >> N;
	N = N[N.length()-1] + N.substr(0,N.length()-1);
*/
/* 文字列合成
	string N,M;
	cin >> N >> M;
	SINT64 ans = 0;
	ans = stoi(N+M);
*/



/* SET コンテナ
	set<SINT32> DATA;
	for (SINT32 i = 0; i < N; i++) {
		SINT32 buf;
		cin >> buf;
		DATA.insert(buf);
	}

	//全表示
    set<string>::iterator it; //  イテレータを用意
    for(it = DATA.begin(); it != DATA.end(); it++) {
        cout << *it << endl;
    }

	//N番目を一部表示
	set<string>::iterator it; //  イテレータを用意
	it = DATA.begin();
	rep (i,0,N) {
		it++;
	}
	cout << *it << endl;
*/

/* map
	map<string,SINT32> mp;
	SINT32 N = 0;
	SINT32 mx = 0;

	cin >> N;
	for (SINT32 i = 0; i < N; i++) {
		string s;
		cin >> s;
		mp[s]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++) {
		mx=max(mx,it->second);
	}

*/
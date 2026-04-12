#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include<bitset>
#include<deque>
#include <map>
#define vint vector<int>
#define vint2 vector<vint>
#define vchar vector<char>
#define vchar2 vector<vchar> 
#define vchar3 vector<vchar2> 
#define pr pair<int,int>
#define vpr vector<pr>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
typedef  long long int ll;
using namespace std;
//CHAR_BIT	ビット フィールドではない最小変数のビット数。	8
//SCHAR_MIN	signed char 型変数の最小値。	–128
//SCHAR_MAX	signed char 型変数の最大値。	127
//UCHAR_MAX	unsigned char 型変数の最大値。	255 (0xff)
//CHAR_MIN	char 型変数の最小値。 - 128、 / J オプション使用時は 0
//CHAR_MAX	char 型変数の最大値。	127、 / J オプション使用時は 255
//MB_LEN_MAX	多文字定数の最大バイト数。	5
//SHRT_MIN	short 型変数の最小値。	–32768
//SHRT_MAX	short 型変数の最大値。	32767
//USHRT_MAX	unsigned short 型変数の最大値。	65535 (0xffff)
//INT_MIN	int 型変数の最小値。	–2147483647 – 1
//INT_MAX	int 型変数の最大値。	2147483647
//UINT_MAX	unsigned int 型変数の最大値。	4294967295 (0xffffffff)
//LONG_MIN	long 型変数の最小値。	–2147483647 – 1
//LONG_MAX	long 型変数の最大値。	2147483647
//ULONG_MAX	unsigned long 型変数の最大値。	4294967295 (0xffffffff)




int  main() {
	int n;
	cin >> n;
	vint a = vint(n);
	REP(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cerr << "-------" << endl;
	REP(i, n) {
		cerr << a[i]<<endl;
	}
	int s=0,e=n-2;
	int sv = a[n - 1];
	int ev = a[n - 1];
	long long int ret = 0;
	int cnt=0;
	while (s<=e) {
		int sv_s = abs(sv - a[s]);//0
		int mi = 0; int m = sv_s; //cerr << "m"<<mi<<"\t"<<m << endl;
		int ev_s = abs(ev - a[s]);//1
		if (ev_s > m) { mi = 1; m = ev_s; }
		int sv_e = abs(sv - a[e]);//2
		if (sv_e > m) { mi = 2; m = sv_e; }
		int ev_e = abs(ev - a[e]);//3
		if (ev_e > m) { mi = 3; m = ev_e; }
		cerr << "m\t" << m << endl;
		ret += m;
		if (mi<2) {
			
			if (mi % 2 == 0) {
				sv = a[s];
			}
			else {
				ev = a[s];
			}
			s++;
		}
		else {
			if ( mi % 2 == 0) {
				sv = a[e];
			}
			else {
				ev = a[e];
			}
			e--;
		}
		cerr << "sv\t" << sv << "ev\t" << ev << endl;

	}
	//ret += a[s];
	cout << ret << endl;

//while (true) {}

	return 0;
}

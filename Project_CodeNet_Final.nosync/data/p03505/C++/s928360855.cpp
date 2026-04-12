// #define _CRT_SECURE_NO_WARNINGS
// #define _USE_MATH_DEFINES	// M_PI=3.1415...
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <locale>
#include <cctype>
#include <sstream>
#include <iomanip>	// 20桁出力 cout << setprecision(20) << double;
#include <queue>
#include <bitset>	// bitset<8> bs1(131uL); // 10000011 bs1[0]は1 01stringからビット集合生成可
#include <numeric>
#include <random>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<pair<LL, LL> > VP;
typedef vector<string> VS;
typedef map<int, int> MAPII;
typedef multimap<int, char, greater<int> > MuMAPIC;
typedef multimap<int, string, greater<int> > MuMIS;
typedef pair<int, int> P;
typedef pair<int, pair<P, P> > PP;

#define INF 999999999999999997;
#define MP make_pair
#define FAST_IO  cin.tie(0); ios::sync_with_stdio(false);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORL(i,a,b) for(LL i=(a);i<(b);i++)
#define FOR_REV(i,a,b) for(int i=(a);i>=(b);i--)
#define foreach_it(type,it,c) for(type::iterator it=c.begin(),c_end=c.end();it!=c_end;++it)
#define FOR_ITR(d) for(auto itr=d.begin(),d_end=d.end();itr!=d_end;++itr)	// C++11
#define O(s) cout<<s<<endl;

#define DUMP_VVI(b) FOR(i,0,b.size()){FOR(j,0,b[i].size())printf("%d ",b[i][j]);puts("");}
#define D_OUT(str,value) if(dbgF){cout<<str<<" : "<<value<<endl;}

template<class T>T IN() { T d; cin >> d; return d; }

LL gcd(LL a, LL b) { return (b > 0) ? gcd(b, a%b) : a; } // 最大公約数（Greatest Common Divisor）
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; } // 最小公倍数（Least Common Multiple）
bool uruu(LL Y) { return (((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0) ? true : false); } // うるう年判定

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dxx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dyy[8] = { 1,1,0,-1,-1,-1,0,1 };

// vector注意
// vec[i][j]の形に入力を入れるとき、vecは初期化してある必要がある.

// ------------------- include, typedef, define END. -------------------

int main() {
	FAST_IO;
	bool dbgF = true; // for D_OUT(str, value)  ... cout<< str <<" : "<< value <<endl;

	LL K, A, B;
	cin >> K >> A >> B;

	if (A <= B) {
		if (K <= A) { O(1); }
		else { O(-1); }
	}
	else {
		LL nowR = A;
		LL plus2 = A - B;
		if (nowR >= K) {
			O(1);
		}
		else {
			// bit数が多いとceilがうまくいかないっぽい。入力例3で間違う。
			//LL nextPlus = ceil((K - nowR) / (double)plus2);
			LL nextPlus = ((K - nowR) + plus2-1) / plus2;
			O(nextPlus * 2 + 1);
		}
	}

	return 0;
}
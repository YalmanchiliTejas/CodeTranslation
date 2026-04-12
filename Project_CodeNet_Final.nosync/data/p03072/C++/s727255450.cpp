#include <bits/stdc++.h>
using namespace std;

/* #pragma */
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


/*alias*/
#define F first
#define S second

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define itn int

/*template*/
template<class T>inline bool amax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>inline bool amin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

/* func */
int32_t GCD(int32_t a, int32_t b){return b ? GCD(b, a%b) : a;}
int64_t GCD(int64_t a, int64_t b){return b ? GCD(b, a%b) : a;}
int32_t LCM(int32_t a, int32_t b){return a * b / GCD(a, b);}
int64_t LCM(int64_t a, int64_t b){return a * b / GCD(a, b);}

/*struct*/
struct aaa {
	aaa() {
		cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20);
	};
}aaaaaaa;

/* const */
constexpr int32_t INF = 1001001001;
constexpr int64_t LINF = 1001001001001001001ll;
constexpr int32_t MOD = 1e9 + 7; //10^9
constexpr int64_t EPS = 1e-9;
constexpr int32_t dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }, dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//constexpr int32_t dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//Counterclockwise from the 6o'clock direction
//Take the x-axis downward and the y-axis right


//g++ -std=c++14 -Wall --pedantic-errors -o template template.cpp
//g++ -std=c++14 -Wall --pedantic-errors template.cpp
//chcp 65001

/*global*/



//#define int int64_t
signed main()
{
	int n; cin >> n;
	vector<int> h(n);
	for(int i = 0, i_len = (int)n; i < i_len; ++i) cin >> h[i];
	
	int max = h[0];
	int cnt = 1;
	for(int i = 1, i_len = (int)n; i < i_len; ++i){

		if(h[i]>=max){
			cnt++;
		}

		amax(max, h[i]);

	}
	cout << cnt << endl;
}
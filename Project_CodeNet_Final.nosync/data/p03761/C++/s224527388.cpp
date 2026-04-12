#include <bits/stdc++.h>
using namespace std;

/* #pragma */
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

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
int GCD(int a,int b){return b?GCD(b,a%b):a;}
long long GCD(long long a, long long b){return b ? GCD(b, a%b) : a;}
int LCM(int a, int b){return a * b / GCD(a, b);}
long long LCM(long long a, long long b){return a * b / GCD(a, b);}

/*struct*/
struct aaa {
	aaa() {
		cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20);
	};
}aaaaaaa;

/* const */
const int INF = 1001001001;
const long long LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7; //10^9
const double EPS = 1e-9;
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }, dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//Counterclockwise from the 6o'clock direction
//Take the x-axis downward and the y-axis right

//#define int long long

//g++ -std=c++14 -Wall --pedantic-errors -o template template.cpp
//g++ -std=c++14 -Wall --pedantic-errors template.cpp
//chcp 65001

/*global*/




signed main()
{
	int n; cin >> n;
	vector<int> a(30, INF);
	vector<string>  s(n);
	for(int i = 0, i_len = (int)n; i < i_len; ++i){
		cin >> s[i];
	}

	for(int i = 0; i < n; ++i){
		vector<int> b(30, 0);
		for(auto c: s[i]){
			b[c -'a']++;
		}
		for(int i = 0; i < 26; ++i){
			a[i] = min(a[i], b[i]);
		}
	}

	string ans{};
	for(int i = 0; i < 26; ++i){
		ans+=string(a[i], 'a'+i);
	}
	cout << ans << endl;
}
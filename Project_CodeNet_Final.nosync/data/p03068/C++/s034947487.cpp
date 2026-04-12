#include <bits/stdc++.h>
using namespace std;

/* #pragma */
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/*alias*/
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define itn int

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
//Counterclockwise from the 6o'clock direction
//Take the x-axis downward and the y-axis right

//#define int long long

//g++ -std=c++14 -Wall --pedantic-errors -fsanitize=signed-integer-overflow -fno-sanitize-recover=all -o template template.cpp


signed main()
{
	int n,k;cin >>n;
	string s; cin >> s;
	cin >> k;

for(int i = 0; i < n; ++i){
	if(s[k-1] != s[i]){
		s[i] = '*';
	}
}

cout << s << endl;
	return 0;
}
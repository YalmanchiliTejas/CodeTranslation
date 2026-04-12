#include <bits/stdc++.h>
 
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n)  for(int i=0;i<(n);++i)
#define REPr(i, n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define FORqr(i, m, n) for(int i = (n);i >=(m);--i)
#define PB push_back
#define MP make_pair
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x,0,sizeof(x))
#define FILL(x, y) memset(x,y,sizeof(x))
#define MM(x) memset(x,-1,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
/* (๑╹◡╹) */
 
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
 
template<class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 /* (๑╹ここにすきなもじをいれてね！╹) */
template<class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
///////////////////////////////////////////////
/* (๑╹最強╹) */




int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll p3 = 1000000000000;
    ll p1 = A*X + B*Y;
    ll p2 = 2*C * max(X,Y);
        if (X<Y)
           p3 = 2*C * X + B * abs(Y-X);
        if (X>Y)
           p3 = 2*C * Y + A * abs(X-Y);
    ll ans = min(p1,min(p2,p3));

cout << ans << endl;

}
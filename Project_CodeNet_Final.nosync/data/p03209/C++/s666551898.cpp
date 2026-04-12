// しゃきょうおぶけんとん
#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
static const ll INF = 1LL << 60;
//Write From this Line

long long rec(int n, long long x){
	long long len = (1LL <<(n+1)) -3 ;
	long long num = (1LL <<n) -1;
	if (n == 0) return 1;
	if (x == 1) return 0;
	else if (x <= len + 1) return rec(n-1, x-1);
	else if (x == len + 2) return num + 1;
	else if (x <= (len + 1) * 2) return num + 1 + rec(n-1, x - len - 2);
	else return num * 2 + 1;
}
int main()
{
	int N; 
	cin >> N; 
	ll X;
	cin >> X;
	cout << rec(N, X) << endl;
}

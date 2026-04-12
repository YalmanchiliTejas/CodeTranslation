#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr long long INF = 2147483647;
constexpr long long INFF = 9223372036854775807;


ll res(long long N,long long X){
    if(N == 0) return 1;
    if(X == 1) return 0;
    long long len = (1LL << (N + 1)) - 3;
    long long pty = (1LL << N) - 1;
    if(X <= len + 1) return res(N - 1, X - 1);
    else if(X == len + 2) return pty + 1;
    else if(X < 2*len + 3) return pty + 1 + res(N - 1,X - len - 2);
    else return 2*pty + 1;
}

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    long long N,X;
    cin >> N >> X;
    cout << res(N,X) << endl;
}

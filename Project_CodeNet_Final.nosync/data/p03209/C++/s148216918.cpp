#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X)
#define debug(x0123456789) cerr<<#x0123456789<<':'<<x0123456789<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto x0123456789:v)cerr<<x0123456789<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define EPS 1e-9
typedef long long ll;
typedef long double ld;

ll sum[51];
ll len[51];

long long POW(long long x,long long n){long long ans = 1;while(n){if(n%2)ans *= x;x *= x;n >>= 1;}return ans;}
long long POW(long long x,long long n,long long mod){long long ans = 1;while(n){if(n%2)ans *= x;x *= x;x %= mod;ans %= mod;n >>= 1;}return ans;}

ll dfs(ll N,ll X){
    if(X==len[N])return sum[N];
    if(X==0)return 0;
    if(X < 2+len[N-1])return dfs(N-1,X-1);
    if(X == 2+len[N-1])return sum[N-1]+1;
    return sum[N-1]+1+dfs(N-1,X-len[N-1]-2);
}

signed main(){
    ll N,X;
    cin >> N >> X;
    FOR(i,0,51)sum[i] = POW(2,i+1)-1;
    FOR(i,0,51)len[i] = POW(2,i+2)-3;
    cout << dfs(N,X) << endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
ll f(ll n,ll x){
    if(n==0){
        return 1;
    }
    ll t=(1LL<<(n+2))-3,p=(1LL<<(n+1))-1;
    ll h=(t+1)/2;
    if(x==1){
        return 0;
    }
    else if(x<h){
        return f(n-1,x-1);
    }
    else if(x==h){
        return (1LL<<n);
    }
    else if(x<t){
        return f(n-1,x-h)+(1LL<<n);
    }
    else{
        return p;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;cin >> n >> x;
    cout << f(n,x) << endl;
}
#include<bits/stdc++.h>
#define rep(i, n) for (ll i=0;i<(n);i++)
using namespace std;
#define vecout(v) for(int i=0;i<v.size();i++) {cout<<v[i]<<endl;}
typedef long long ll;

vector<ll> p;
vector<ll> a;
ll n;
ll x;

ll f(ll N, ll X){
    if(N==0) {
        if(X<=0) return 0;
        else return 1;
    }
    else if(X<=p[N-1]+1) return f(N-1, X-1);
    else if(x==p[N-1]+2) return a[N-1]+1;
    else return a[N-1]+f(N-1, X-2-p[N-1])+1;
}
int main(void){
    cin>>n>>x;
    p.resize(n+1);
    a.resize(n+1);
    p[0]=1;
    a[0]=1;
    for(ll i=1;i<=n;i++){
        p[i]=2*p[i-1]+3;
    }
    for(ll i=1;i<=n;i++){
        a[i]=2*a[i-1]+1;
    }
    ll ans=f(n, x);
    cout<<ans<<endl;
    return 0;

}
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
#define ms multiset
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
ll fa[MAX];
ll power(ll p,ll q){
    ll res=1;
    p%=mod;
    while(q){
        if (q&1)
            res=(res*p)%mod;
        q>>=1;
        p=(p*p)%mod;
    }
    return res;
}
ll fact(ll n){
    if (n<=1)
        return fa[n]=1;
    if (fa[n])
        return fa[n];
    return fa[n]=(n*fact(n-1))%mod;
}
ll ncr(ll n,ll r){
    if (!r)
        return 1;
    return (((fact(n)*power(fact(n-r),mod-2))%mod)*power(fact(r),mod-2))%mod;
}
void solve(){
    ll n;
    cin>>n;
    if (n>=30)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
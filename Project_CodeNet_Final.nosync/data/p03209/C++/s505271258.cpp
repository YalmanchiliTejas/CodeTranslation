#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
set<string> c;
map<ll,ll> mp;
const ll inf=100000000000000000;
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
ll L[100];
ll f(ll n,ll x){
    if(n==0)return 1;
    else if(x==1)return 0;
    else if(x>=1&&x<=1+L[n-1])return f(n-1,x-1);
    else if(x==L[n-1]+2)return f(n-1,L[n-1])+1;
    else if(x>=(L[n-1]+3)&&x<=(2*(L[n-1]+1)))return f(n-1,L[n-1])+1+f(n-1,x-(L[n-1]+2));
    else if(x==(2*L[n-1]+3))return 2*f(n-1,L[n-1])+1;
    return 0;
}
int main(){
    ll n,x;cin>>n>>x;
    L[0]=1;
    for(int i=1;i<n+1;i++){
        L[i]=L[i-1]*2+3;
    }
    cout<<f(n,x)<<endl;
}

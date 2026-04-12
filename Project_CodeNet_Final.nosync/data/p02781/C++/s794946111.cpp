#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


ll comb(ll n,ll k){
    if(k<0 || n<k)return 0;
    if(k==0 || n==k)return 1;
    if(k==1)return n;
    if(k==2)return (n*(n-1))/2;
    return (n*(n-1)*(n-2))/6;
}

string s;
ll n;
ll memo[200][5];

ll hoge(ll i,ll x){
    if(memo[i][x]!=0)return memo[i][x];
    if(n-i<x)return memo[i][x]=0;
    string t;
    t=s[i];
    ll a=stoll(t);
    if(i==n-1){
        if(x==1){
            return memo[i][x]=a;
        }else{
            return memo[i][x]=0;
        }
    }
    if(a==0){
        return memo[i][x]=hoge(i+1,x);
    }else if(a==1){
        if(x==1){
            return memo[i][x]=1+comb(n-i-1,x)*pow(9,x);
        }
        return memo[i][x]=hoge(i+1,x-1)+comb(n-i-1,x)*pow(9,x);
    }else{
        if(x==1){
            memo[i][x]=comb(n-i-1,x-1)*pow(9,x-1)*(a-1)+comb(n-i-1,x)*pow(9,x)+1;
        }
        return memo[i][x]=comb(n-i-1,x-1)*pow(9,x-1)*(a-1)+comb(n-i-1,x)*pow(9,x)+hoge(i+1,x-1);
    }
}

int main(){
    cin>>s;
    ll k;cin>>k;
    n=s.size();
    ll ans=hoge(0,k);
    cout<<ans<<endl;
    
    return 0;
}


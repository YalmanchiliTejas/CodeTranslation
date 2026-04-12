#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> cnt(n,vector<ll>(26,0));
    string s;
    rep(i,n){
        cin>>s;
        rep(j,s.size()) cnt[i][s[j]-'a']++;
    }
    vector<ll> mincnt(26,0);
    rep(i,26){
        ll mn=50;
        rep(j,n){
            mn=min(mn,cnt[j][i]);
        }
        mincnt[i]=mn;
    }
    string ans="";
    rep(i,26){
        rep(j,mincnt[i]){
            ans.push_back('a'+i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1001001001;
const long long MOD = 998244353;
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,x,m;
    cin>>n>>x>>m;
    map<ll,pair<int,int>> mp;
    vector<ll> c_sum;
    ll a=x,cnt=1;
    c_sum.emplace_back(0);
    c_sum.emplace_back(a);
    while(++mp[a].first<=1){
        mp[a].second=cnt;
        cnt++;
        a%=m;
        a*=a;
        a%=m;
        c_sum.emplace_back(c_sum.back()+a);
    }
    ll t=(cnt-1)-(mp[a].second-1),v=c_sum[cnt-1]-c_sum[mp[a].second-1];
    ll ans=((n-(mp[a].second-1))/t)*v;
    ll b=x;
    for(ll i=1;i<mp[a].second;i++){
        ans+=b;
        b%=m;
        b*=b;
        b%=m;
    }
    n-=mp[a].second-1;
    n%=t;
    for(ll i=1;i<=n;i++){
        ans+=a;
        a%=m;
        a*=a;
        a%=m;
    }
    cout<<ans<<endl;
}
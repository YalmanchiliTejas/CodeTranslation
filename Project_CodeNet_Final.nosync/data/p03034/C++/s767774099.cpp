#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);
//ios::sync_with_stdio(false);


signed main(){
    ll n,ans=0;cin>>n;
    vector<ll> v(n);
    rep(i,n)cin>>v[i];
    ans=0;

    for(int i=1;i < n-1;i++)//a-b
    {
        ll res=0;
        set<ll> se;
        for(int j=1;i*(j+1)<n-1;j++)//係数
        {
            if(!se.count(i*j) && !se.count(n-1-i*j) && i*j!=n-1-i*j){
                res+=v[i*j]+v[n-1-i*j];
                ans=max(ans,res);
                se.emplace(i*j);
                se.emplace(n-1-i*j);
                //cout<<i*j<<" "<<n-1-i*j<<endl;
            }
        }
        se.clear();
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<ll>cnt(n);
    ll sum=0;
    bool f=0;
    ll ans=0;
    while(!f){
        bool ff=1;
        sum=0;
        rep(i,n)cnt[i]=0;
        rep(i,n){
            if(a[i]>=n){
                ff=0;
                ll s=a[i]-n+1;
                cnt[i]=(s-1)/n+1;
                sum+=cnt[i];
                a[i]-=cnt[i]*n;
            }
        }
        f|=ff;
        ans+=sum;
        rep(i,n){
            a[i]+=sum-cnt[i];
        }
    }
    cout<<ans<<endl;
}
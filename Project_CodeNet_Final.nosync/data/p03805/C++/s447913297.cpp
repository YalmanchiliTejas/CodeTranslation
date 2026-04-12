#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
long long fac(ll a){
    long long ans=1;
    while(a>1){
        ans*=a;
        ans%=1000000007;
        a--;
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    vvl v(n);
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    vl info(n);
    ll ans=0;
    rep(i,n)info[i]=i;
    while(info[0]==0){
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<v[info[i]].size();j++){
                if(info[i+1]==v[info[i]][j])count++;
            }
        }
        if(count==n-1)ans++;
        next_permutation(all(info));
    }
    cout << ans << endl;
}
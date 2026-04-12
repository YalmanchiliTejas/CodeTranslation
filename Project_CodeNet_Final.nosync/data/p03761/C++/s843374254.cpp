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
        a--;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> info(26,inf);
    rep(i,n){
        vector<int> count(26,0);
        string s;
        cin >> s;
        rep(i,s.size()){
            count[s[i]-'a']++;
        }
        rep(i,26){
            info[i]=min(info[i],count[i]);
        }
    }
    string ans;
    rep(i,26){
        for(int j=0;j<info[i];j++){
            ans.push_back('a'+i);
        }
    }
    cout << ans << endl;
}

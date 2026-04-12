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
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    string k;cin>>k;
    ll d;cin>>d;
    vector<mat> dp(2,mat(k.size()+1,vec(d)));
    dp[0][0][0]=1;
    rep(i,k.size()){
        ll t=k[i]-'0';
        rep(j,d){
            rep(l,t){
                dp[1][i+1][(j+l)%d]=(dp[1][i+1][(j+l)%d]+dp[0][i][j])%inf;
            }
            dp[0][i+1][(j+t)%d]=(dp[0][i+1][(j+t)%d]+dp[0][i][j])%inf;
            rep(l,10){
                dp[1][i+1][(j+l)%d]=(dp[1][i+1][(j+l)%d]+dp[1][i][j])%inf;
            }
        }
    }
    ll ans=(dp[0][k.size()][0]+dp[1][k.size()][0]-1)%inf;
    if(ans<0)ans+=inf;
    cout<<ans<<endl;
}
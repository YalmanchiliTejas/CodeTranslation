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
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    string s;cin>>s;
    ll K;cin>>K;
    vector<vector<vector<ll> > >dp(s.size()+1,vector<vector<ll> >(2,vector<ll>(4)));
    dp[0][0][0]=1;
    rep(i,s.size()){
        ll t=s[i]-'0';
        rep(k,4){
            rep(l,t){
                if(l==0)dp[i+1][1][k]+=dp[i][0][k];
                else if(k==3)continue;
                else dp[i+1][1][k+1]+=dp[i][0][k];
            }
            if(t>0){
                if(k<3)dp[i+1][0][k+1]+=dp[i][0][k];
            }else{
                dp[i+1][0][k]+=dp[i][0][k];
            }
            rep(l,10){
                if(l==0)dp[i+1][1][k]+=dp[i][1][k];
                else if(k==3)continue;
                else dp[i+1][1][k+1]+=dp[i][1][k];
            }
        }
    }
    rep(i,4){
        rep(j,2){
            //cout<<i<<' '<<j<<' '<<dp[s.size()][j][i]<<endl;
        }
    }
    cout<<dp[s.size()][0][K]+dp[s.size()][1][K]<<endl;
}
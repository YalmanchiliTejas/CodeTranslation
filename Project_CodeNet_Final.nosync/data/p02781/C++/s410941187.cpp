#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    string s;cin>>s;
    int n=s.size();
    int x;cin>>x;
    //0じゃないのがちょうどx個
    ll dp[n+1][x+10][2];//1なら越えない
    rep(i,n+1)rep(j,x+1)rep(k,2) dp[i][j][k]=0;
    dp[0][0][0]=1;
    rep(i,n){
        const int tar=s[i]-'0';
        rep(j,x+1){
            rep(k,2){
                for(int d=0;d<(k?10:(tar+1));d++){
                    if(d==0){
                        dp[i+1][j][k||d<tar]+=dp[i][j][k];
                    }else{
                        dp[i+1][j+1][k||d<tar]+=dp[i][j][k];
                    }
                }
            }
        }
    }
    cout<<dp[n][x][1]+dp[n][x][0]<<endl;
    return 0;
}

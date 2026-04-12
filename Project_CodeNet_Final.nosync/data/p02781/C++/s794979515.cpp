#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

string s;
vector<long long> N;
int dp[110][2][4];

int main(void){
    cin>>s;
    int k;
    cin>>k;
    int l=s.size();
    rep(i,l) N.push_back(s[i]-'0');
    dp[0][0][0]=1;
    dp[0][0][1]=0;
    dp[0][0][2]=0;
    dp[0][0][3]=0;
    dp[0][1][0]=0;
    dp[0][1][1]=0;
    dp[0][1][2]=0;
    dp[0][1][3]=0;
    rep(i,l){
        rep(smaller,2){
            rep(j,4){
                for(int x=0;x<=(smaller ? 9 : N[i]);x++){
                    if(x==0){
                        dp[i+1][smaller || x<N[i]][j]+=dp[i][smaller][j];
                    }
                    else{
                        if(j!=k){
                            dp[i+1][smaller || x<N[i]][j+1]+=dp[i][smaller][j];
                        }
                    }
                }
            }
        }
    }
    //rep(i,l) cout<<N[i]<<endl;
    //rep(i,l+1) rep(smaller,2) rep(j,4) cout<<i<<" "<<smaller<<" "<<j<<" "<<dp[i][smaller][j]<<endl;
    cout<<dp[l][0][k]+dp[l][1][k]<<endl;
    return 0;
}
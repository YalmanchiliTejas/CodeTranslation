#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
using namespace std;
//const ll inf=(1e+10)+1;
int dp[101][4][2];
int main(void){
    string s;cin>>s;
    int n=s.size();
    int k;cin>>k;
    //int dp[101][4][2];グローバル変数にしないと初期値がバグる！！
    dp[0][0][0]=1;
    rep(i,n){
        int now=s[i]-'0';
        rep(j,4){
            rep(l,2){
                rep(a,10){
                    int ni=i+1,nj=j,nl=l;
                    if(a!=0)nj++;
                    if(nj>k)continue;
                    if(l==0){
                        if(a>now)break;
                        if(a<now)nl=1;
                        else nl=0;
                    }
                    dp[ni][nj][nl]+=dp[i][j][l];
                }
            }
        }
    }
    ll res=dp[n][k][1]+dp[n][k][0];
    cout<<res<<endl;
}

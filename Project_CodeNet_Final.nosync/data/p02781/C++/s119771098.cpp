//解説ガン見 後でもう一回解きます
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=0;i<=(int)n;i++)
ll dp[105][4][2];
int main(void){
    string n;
    int k;
    cin>>n>>k;
    ll sz=n.size();
    dp[0][0][0]=1;
    
    rep(i,sz){
        rep(j,4){
            rep(l,2){
                int now=n[i]-'0';
                rep(d,10){
                    int ni=i+1,nj=j,nl=l;
                    if(d!=0) nj++;
                    if(nj>k) continue;
                    if(l==0){
                        if(d>now) continue;
                        else if(d<now) nl=1;
                        else nl=0;
                    }
                    dp[ni][nj][nl] += dp[i][j][l];
                }
            }
        }
    }
    
    ll res=dp[sz][k][1]+dp[sz][k][0];
    cout<<res<<endl;
}
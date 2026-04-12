#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
int dp[105][4][2];
int main(){
    string s;cin >> s;
    int K;cin >> K;
    int n=s.size();
    for(int i=0; i<105; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<2; k++){
                dp[i][j][k]=0;
            }
        }
    }
    dp[0][0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=K; j++){
            for(int k=0; k<=1; k++){
                int nd=s[i]-'0';
                for(int d=0; d<10; d++){
                    int ni=i+1,nj=j,nk=k;
                    if(d!=0) nj++;
                    if(nj>K) continue;
                    if(k==0){
                        if(d>nd) continue;
                        if(d<nd) nk=1;
                    }
                    dp[ni][nj][nk]+=dp[i][j][k];
                }
            }
        }
    }
    int ans=dp[n][K][0]+dp[n][K][1];
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=205,INF=1<<30;
int dp[2*MAX][MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<vector<int>> S(H,vector<int>(W));
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i][j];
        }
    }
    
    for(int s=2;s<=H+W;s++){
        for(int a=1;a<=H;a++){
            if(1<=s-a&&s-a<=W){
                for(int b=1;b<=H;b++){
                    if(1<=s-b&&s-b<=W){
                        if(a==b){
                            for(int bit=0;bit<4;bit++){
                                dp[s][a][b]=max(dp[s][a][b],dp[s-1][a-bit/2][b-bit%2]+S[a-1][s-a-1]);
                            }
                        }else{
                            for(int bit=0;bit<4;bit++){
                                dp[s][a][b]=max(dp[s][a][b],dp[s-1][a-bit/2][b-bit%2]+S[a-1][s-a-1]+S[b-1][s-b-1]);
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout<<dp[H+W][H][H]<<endl;
}





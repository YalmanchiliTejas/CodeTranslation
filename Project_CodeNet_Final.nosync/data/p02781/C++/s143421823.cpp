#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<tuple>
#include<cmath>


#define MOD 1000000007
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back

typedef long long ll;

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    string N;
    int K;
    cin>>N>>K;

    int dp[2][5][1000]={};
    dp[1][0][0]=0;
    dp[1][1][0]=1;
    dp[1][2][0]=0;
    dp[1][3][0]=0;
    dp[0][0][0]=1;
    dp[0][1][0]=int(N[0]-'1');
    dp[0][2][0]=0;
    dp[0][3][0]=0;

    rep(i,1,N.size()){
        if(N[i] == '0'){
            rep(j,0,4){
                dp[1][j][i]=dp[1][j][i-1];
            }
        }
        else{
            rep(j,1,4){
                dp[1][j][i]=dp[1][j-1][i-1];
            }
        }
    }

    rep(i,0,N.size()-1){
        rep(j,0,4){
            dp[0][j][i+1] += dp[0][j][i]; 
            dp[0][j+1][i+1] += dp[0][j][i]*9;
            if(N[i+1] != '0'){
                dp[0][j][i+1] += dp[1][j][i];
                dp[0][j+1][i+1] += dp[1][j][i]*int(N[i+1]-'1');
            }
        }
    }

    cout<<dp[0][K][N.size()-1] + dp[1][K][N.size()-1]<<endl;

    return 0;
}
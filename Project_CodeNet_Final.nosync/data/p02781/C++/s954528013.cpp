#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    string N;
    int K;
    cin >> N >> K;

    int len=N.size();
    
    vector<vector<vector<ll> > > dp(len+1,vector<vector<ll> >(K+1, vector<ll>(2,0)));
    dp[0][0][0]=1;
    for(int i=0; i<len; i++){
        for(int j=0; j<=K; j++){
            if(N[i]=='0'){
                dp[i+1][j][1]+=dp[i][j][1];
                dp[i+1][j][0]+=dp[i][j][0];
                if(j+1>K)continue;
                dp[i+1][j+1][1]+=dp[i][j][1]*9;
            }else{
                dp[i+1][j][1]+=dp[i][j][1]+dp[i][j][0];
                if(j+1>K)continue;
                dp[i+1][j+1][1]+=dp[i][j][1]*9+dp[i][j][0]*(N[i]-'1');
                dp[i+1][j+1][0]+=dp[i][j][0];
            }
        }
    }
    //cout << dp[1][0][1] << endl;
    cout << dp[len][K][1]+dp[len][K][0] << endl;
}
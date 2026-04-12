#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll const MOD=1'000'000'007;

string N;
ll K;
ll dp[101][4][2];

int main(){
    cin>>N>>K;

    repn(i,N.size()) dp[i][0][0]=1;
    dp[1][1][0]=N[0]-'0'-1;
    dp[1][1][1]=1;
    repn(i,N.size()-1){
        repn(j,K){
            if(N[i]!='0') dp[i+1][j][1]=dp[i][j-1][1];
            else dp[i+1][j][1]=dp[i][j][1];
            dp[i+1][j][0]+=dp[i][j-1][0]*9;
            dp[i+1][j][0]+=dp[i][j][0];
            dp[i+1][j][0]+=dp[i][j-1][1]*max(0,N[i]-'0'-1);
            if(N[i]!='0') dp[i+1][j][0]+=dp[i][j][1];
        }
    }

    int ans=dp[N.size()][K][0]+dp[N.size()][K][1];

    cout<<ans<<endl;
}
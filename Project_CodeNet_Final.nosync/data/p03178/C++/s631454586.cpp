#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)

long long M = 1000000007;

int n;
typedef vector<vector<long long>> Mat;

int main(int argc, char const *argv[]) {
    string s;cin>>s;
    int n = s.length();
    int d;cin>>d;
    vector<vector<long long>> dp(n+1,vector<long long>(d,0)),dp9(n+1,vector<long long>(d,0));
    dp[0][0] = 1;
    dp9[0][0] = 1;
    for(int i=0;i<n;++i){
        for(int k=0;k<d;++k){
            for(int l=0;l<10;++l){
                dp9[i+1][k] += dp9[i][(((k-l)%d)+d)%d];
                dp9[i+1][k] %= M;
            }
        }
        char c = s[n-i-1];
        int m = c - '0';
        for(int k=0;k<d;++k){
            for(int l=0;l<m;++l){
                dp[i+1][k] += dp9[i][(((k-l)%d)+d)%d];
                dp[i+1][k] %= M;
            }
            dp[i+1][k] += dp[i][(((k-m)%d)+d)%d];
            dp[i+1][k] %= M;
        }
    }
    cout<<(dp[n][0]+M-1)%M<<endl;
    return 0;
}
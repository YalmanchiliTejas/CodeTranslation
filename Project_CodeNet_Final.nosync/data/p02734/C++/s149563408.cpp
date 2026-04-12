#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=998244353;
int main()
{
	int n, s;
    cin>>n>>s;
    int a[3030];
    for(int i=0; i<n; i++) cin>>a[i];
    ll dp[3030][3030]={};
    dp[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=s; j++){
            if(dp[i][j]==0) continue;
            if(j==0 && j+a[i]<s){
                (dp[i+1][j+a[i]]+=dp[i][j]*(i+1))%=MOD;
            }else if(j && j+a[i]==s){
                (dp[i+1][j+a[i]]+=dp[i][j]*(n-i))%=MOD;
            }else if(j==0 && j+a[i]==s){
                (dp[i+1][j+a[i]]+=dp[i][j]*(n-i)*(i+1))%=MOD;
            }else if(j+a[i]<=s){
                (dp[i+1][j+a[i]]+=dp[i][j])%=MOD;
            }
            (dp[i+1][j]+=dp[i][j])%=MOD;
        }
    }
    cout<<dp[n][s]<<endl;
	return 0;
}

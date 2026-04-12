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

vector<vector<long long>> dp;
vector<long long> a;

long long solve(int l, int r){
    if(dp[l][r] != 1ll<<62)return dp[l][r];
    if(l == r)return 0;
    dp[l][r] = max(a[l] - solve(l+1,r), a[r-1] - solve(l,r-1));
    return dp[l][r];
}

int main(int argc, char const *argv[]) {
    long long n;cin>>n;
    a = vector<long long>(n);
    dp = vector<vector<long long>>(n+1,vector<long long>(n+1,1ll<<62));
    for(int i=0;i<n;++i)cin>>a[i];
    cout<<solve(0,n)<<endl;
    return 0;
}
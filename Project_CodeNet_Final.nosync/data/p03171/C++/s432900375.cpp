#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[3005];
long long memo[3005][3005];
long long dp(int l,int r);
signed main(){
    cin.tie(0); 
    ios::sync_with_stdio(false);
    int n;
    long long sum = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    memset(memo,-1,sizeof(memo));
    cout << dp(0,n-1) << "\n";
    return 0;
}
long long dp(int l,int r){
    if(memo[l][r] != -1){
        return memo[l][r];
    }
    if(l == r){
        return a[l];
    }else{
        return memo[l][r] = max(a[l]-dp(l+1,r),a[r]-dp(l,r-1));
    }
}

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
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;
int main()
{
    int n, m; cin>>n>>m;
    string s; cin>>s;
    int j=0;
    vector<int> v;
    bool nuo=1;
    for(int i=1; i<m; i++){
        if(s[i]!=s[0]){
            nuo=0;
            v.push_back(i-j);
            j=i+1;
        }
    }
    if(nuo){
        ll dp[2][200002]={};
        dp[0][0]=1;
        for(int i=1; i<n; i++){
            dp[1][i]+=dp[0][i-1];
            dp[0][i]+=(dp[0][i-1]+dp[1][i-1]);
            dp[0][i]%=MOD;
            dp[1][i]%=MOD;
        }
        ll ans=dp[0][n-1]+dp[1][n-1];
        fill(dp[0], dp[0]+n+1, 0);
        fill(dp[1], dp[1]+n+1, 0);
        dp[1][0]=1;
        for(int i=1; i<n; i++){
            dp[1][i]+=dp[0][i-1];
            dp[0][i]+=(dp[0][i-1]+dp[1][i-1]);
            dp[0][i]%=MOD;
            dp[1][i]%=MOD;
        }
        ans+=dp[0][n-1];
        ans%=MOD;
        cout<<ans<<endl;
        return 0;
    }
    if(n%2==1){
        cout<<0<<endl;
        return 0;
    }
    int mx=v[0]+1-v[0]%2;
    for(int i=1; i<v.size(); i++){
        if(v[i]&1) mx=min(mx, v[i]);
    }
    ll dp[200002]={}, sum[200002];
    dp[0]=1;
    sum[0]=1;
    for(int i=1; i<=n; i++){
        if(i&1) sum[i]=sum[i-1];
        else{
            if(i-mx-3>=0) dp[i]=(sum[i-2]-sum[i-mx-3]+MOD)%MOD;
            else dp[i]=sum[i-2];
            sum[i]=(sum[i-1]+dp[i])%MOD;
        }
    }
    ll ans=0;
    for(int i=1; i<=min(mx, n-1); i+=2){
        ans+=(ll)(i+1)*dp[n-i-1];
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
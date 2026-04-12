#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007
    
long long mod_pow(long long a,long long b)
{
    a %= MOD;
    long long res = 1;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
    
ll dp[110][110];

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0] = 0;
    rep(i,n) cin >> a[i+1];
    n++;
    vector<int> b = a;
    b.push_back(1);
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    int m = b.size();
    map<ll,int>mp;        
    rep(i,b.size()){
        mp[b[i]] = i;
    }
    
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        int K = mp[a[i]];
        if(a[i]<=a[i-1]){
            for(int j=K+1;j<m;j++){
                dp[i-1][0] += dp[i-1][j];
                dp[i-1][0] %= mod;
            }
            dp[i][0] = dp[i-1][0]*2%mod;
            for(int j=1;j<=K;j++){
                dp[i][j] = dp[i-1][j];
            }
        }else{
            int L = mp[a[i-1]];
            dp[i][0] = dp[i-1][0]*2%mod;
            //cerr <<"L: "<<  L << " K: " << K << endl;
            for(int j=1;j<=L;j++){
                dp[i][j] = dp[i-1][j]*mod_pow(2,a[i]-a[i-1])%mod;    
            }
            for(int j=L+1;j<=K;j++){
                if(a[i-1]==0){
                    if(b[j]!=1)dp[i][j] = 2*((mod + mod_pow(2,a[i]-b[j-1]) - mod_pow(2,a[i]-b[j]) )%mod)%mod;
                }else if(b[j]!=1)dp[i][j] = 2*dp[i-1][0]*((mod + mod_pow(2,a[i]-b[j-1]) - mod_pow(2,a[i]-b[j]) )%mod)%mod;        
                //cerr <<a[i-1] << " " << a[i] << " " << b[j] << endl;
                //cerr << dp[i-1][0] << " " << (mod + mod_pow(2,a[i]-a[i-1]) -2*mod_pow(2,a[i]-b[j]) )%mod << endl;
            }
        }
        // rep(j,m){
        //     cerr << dp[i][j] << " ";
        // }
        // cerr << endl;
    }
    ll sm = 0;
    for(int i=0;i<m;i++){
        sm += dp[n-1][i];
        sm %= mod;
    }
    cout << sm << endl;
    return 0;
}
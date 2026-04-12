
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#define PIE 3.14159265358979
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
typedef long long ll;


const ll MOD=1e9+7;
vector<int> K;
ll dp[100015][105];
ll D;
int N;

int main(){
    string str;
    cin>>str;
    cin>>D;
    ll bigD = 100*D;
    N=str.length();
    K.resize(N);
    rep(i,N){
        K[i]=(ll)(str[i]-'0');
    }
    rep(i,D){
        dp[0][i]=0;
    }
    dp[0][0]=1;
    rep(i,N){
        rep(j,D){
            ll &next = dp[i+1][j];
            next = 0;
            rep(k,10){
                next += dp[i][(j+bigD-k)%D];
                next %= MOD;
            }
        }
    }
//    rep(i,N){
//        rep(j,D){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    ll ans = MOD-1;
    ll digsum = 0;
    rep(i,N){
        rep(j,K[i]){
            ans += dp[N-1-i][(bigD-j-digsum)%D];
            ans %= MOD;
        }
        digsum += K[i];
        digsum %= D;
    }
    if(digsum==0){
        ans = (ans+1)%MOD;
    }
    cout<<ans<<endl;
}


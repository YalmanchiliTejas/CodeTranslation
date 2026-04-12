#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string S,T,U;
ll K;
string n;
ll N[101];
ll ans;
ll M;
ll dp[101][101];
int cnt;
ll cntt;
 
 
 
int main(){
    cin >> n>>K;
    ll a = n.size();
    for (int i=0;i<a;i++){
        N[i] = n[i] -'0';
    }
    cnt = 0;
    for(int i=0;i<a;i++){
        cntt = max(cnt,i);
        dp[i][0] = 1;
        for(int j=0;j<=cntt;j++){
            if(cnt==j){
               dp[i+1][j+1] = dp[i][j+1] +N[i]+(dp[i][j]-1)*9;
            } else {
                dp[i+1][j+1] = dp[i][j+1] + dp[i][j]*9;
            }
        }
        if(N[i]!=0){
            cnt++;
        }
        
    }
    cout << dp[a][K] << endl;
//    }else if(a==K){
//        int b=1;
//        for(int i = 0;i<K;i++){
//            M += b*N[K-i-1];
//            b *= 10;
//        }
//        ans = M - (b/10 - 1)-M/10;
//        cout << ans << endl;
//    }else{
//        int b=1;
//        for(int i = 0;i<K;i++){
//            M += b*N[K-i-1];
//            b *= 10;
//        }
//        ans = M - (b/10 - 1)-M/10 + (b - 1)*(a-K);
//        cout << ans << endl;
//    }
    
 
    
}
 
 

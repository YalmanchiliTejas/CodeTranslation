// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
 
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n = s.size();
    ll dp[n+1][k+1][2]={};
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            dp[i+1][j][1] += dp[i][j][1]; // 確定 -> 確定
            if(s[i]=='0') dp[i+1][j][0] += dp[i][j][0]; // 0 未確定->未確定
            if(s[i]!='0') dp[i+1][j][1] += dp[i][j][0]; // 0　未確定->確定
            for(int h=1;h<=9;h++){
                if(j+1<=k && s[i]==('0'+h)) dp[i+1][j+1][0] += dp[i][j][0]; //0以外 未確定->未確定
                if(j+1<=k){
                    dp[i+1][j+1][1] += dp[i][j][1]; // 0以外 確定 ->　確定
                    if('0'+h < s[i]) dp[i+1][j+1][1] += dp[i][j][0]; // 0以外 未確定 -> 確定
                }
            }
        }
    }
    ll ans = dp[n][k][0] + dp[n][k][1];
    cout << ans << endl;


}


// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://cppreference.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   https://www.boost.org/doc/

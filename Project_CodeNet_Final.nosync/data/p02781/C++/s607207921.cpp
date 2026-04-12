#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    string s;
    int k;
    cin >> s >> k;
    ll dp0[101][101],dp1[101][101];
    rep(i,101){
        rep(j,101){
            dp0[i][j] = dp1[i][j] = 0;
        }
    }

    int n = s.length();

    int tmp = s[0] - '0';
    dp0[1][0] = 1;
    dp0[1][1] = tmp - 1;
    dp1[1][1] = 1;

    reps(i,1,n){
        rep(j,4){
            dp0[i+1][j]   +=     dp0[i][j];
            dp0[i+1][j+1] += 9 * dp0[i][j];
        }

        int num = s[i] - '0';
        if(num == 0){
            rep(j,4){
                dp1[i+1][j] += dp1[i][j]; 
            }
        }else{
            rep(j,4){
                dp0[i+1][j]     += dp1[i][j];
                dp0[i+1][j+1]   += (num-1)*dp1[i][j];
                dp1[i+1][j+1]   += dp1[i][j];
            }
        }
    }

    cout << dp0[n][k] + dp1[n][k] << endl;
    return 0;
}
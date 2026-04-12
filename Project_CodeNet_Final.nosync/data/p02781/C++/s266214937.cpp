#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


ll fact[101];

int main(){
    string n;
    ll k;
    cin >> n >> k;

    fact[0] = 1;
    for(int i = 1; i <= 100; i++){
        fact[i] = fact[i-1]*i;
    }

    ll dp0[n.length()+1][k+1], dp1[n.length()+1][k+1];
    for(int i = 0; i < k+1; i++){
        dp0[0][i] = 0;
        dp1[0][i] = 0;
    }
    dp0[0][0] = 0;
    dp1[0][0] = 1;
    for(int i = 1; i <= n.length(); i++){
        for(int j = 0; j <= k; j++){
            int d = n[i-1]-'0';
            
            dp0[i][j] = dp0[i-1][j];
            if(j != 0){
                dp0[i][j] += dp0[i-1][j-1]*9;
                if(d != 0){
                    dp0[i][j] += dp1[i-1][j-1]*(d-1);
                    dp0[i][j] += dp1[i-1][j];
                }
            } else {
                dp0[i][j] = 1;
            }

            if(d != 0){
                if(j != 0){
                    dp1[i][j] = dp1[i-1][j-1];
                } else {
                    dp1[i][j] = 0;
                }
            } else {
                dp1[i][j] = dp1[i-1][j];
            }
        }
    }

    cout << dp0[n.length()][k] + dp1[n.length()][k] << endl;

    return 0;
}
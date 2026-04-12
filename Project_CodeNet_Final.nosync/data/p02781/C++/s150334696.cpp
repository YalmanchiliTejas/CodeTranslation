#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    string N;
    int K;
    cin >> N >> K;

    ll dp[110][2][5];
    for(int j=0; j<2; j++){
        for(int k=0; k<5; k++){
            dp[0][j][k] = 0;
        }
    }
    dp[0][1][1] = 1;
    dp[0][0][1] = N[0] - '0' - 1;
    dp[0][0][0] = 1;

    for(int i=1; i<N.size(); i++){
        int n = N[i] - '0';
        for(int k=0; k<5; k++){
            dp[i][1][k] = 0;
            dp[i][0][k] = dp[i-1][0][k];
            if(n == 0){
                dp[i][1][k] = dp[i-1][1][k];
            }
            else{
                dp[i][0][k] += dp[i-1][1][k];
            }
            if(k > 0){
                dp[i][0][k] += dp[i-1][0][k-1] * 9;
                if(n != 0){
                    dp[i][1][k] += dp[i-1][1][k-1];
                    dp[i][0][k] += dp[i-1][1][k-1] * (n-1);
                }
            }
        }
    }

    cout << dp[N.size()-1][0][K] + dp[N.size()-1][1][K] << endl;

    // for(int i=0; i<N.size(); i++){
    //     for(int j=0; j<2; j++){
    //         for(int k=0; k<5; k++){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
}
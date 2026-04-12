#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <random>
#include <complex>
#include <chrono>
#include <assert.h>

using namespace std;

//ifstream fin("input.in");
//ofstream fout("output.out");

typedef long long LL;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18 + 1;
const int N = 200555;
const int AMAX = 205;
const int LIM = 1000000000;

//typedef __uint128_t u128;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char invdir[]{'L', 'U', 'R', 'D'};
const char dir[]{'R', 'D', 'L', 'U'};

#define all(a) (a).begin(), (a).end()
#define forn(i,a,b) for (int i = a; i <= b; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rc(s) return cout<<s,0
#define pi pair <int, int>

int n,m,D,dp[N][2],dp1[N][2];

string K;

void solve(){
    cin >> K >> D;

    dp[0][0] = 1;
    dp[0][1] = 0;

    for(int i = K.length() - 1; i >= 0; i--){
        int x = K[i] - '0';

        for(int sum = 0; sum < D; sum++){
            // dp[rest] [0] - solutii cu digit <= x pe pozitia anterioara
            // dp[rest] [1] - solutii cu digit > x pe pozitia anterioara

            // 3 Cazuri:

            // 1. Pe pozitia curenta digit < x (solutie de tip 0)
                // dp[...][0] si dp[...][1]. Ex  K=232  1XY (1 < 2)
            // 2. Pe pozitia curenta digit == x (solutie de tip 0)
                // dp[...][0]. Ex  K=232  2XY (1 < 2)
            // 3. Pe pozitia curenta digit == x (solutie de tip 1)
                // dp[...][1]
            // 4. Pe pozitia curenta digit > x (solutie de tip 1)
                // dp[...][0] + dp[...][1]. Ex  K=332  3XY (3 > 2)


            for(int dig = 0; dig <= 9; dig++){
                if(dig == x){
                    dp1[(sum + dig) % D][0] += (dp[sum][0])%MOD;
                    dp1[(sum + dig) % D][0] %= MOD;

                    dp1[(sum + dig) % D][1] += (dp[sum][1])%MOD;
                    dp1[(sum + dig) % D][1] %= MOD;
                }else{
                    dp1[(sum + dig) % D][(dig > x)] += (dp[sum][1] + dp[sum][0]) % MOD;
                    dp1[(sum + dig) % D][(dig > x)] %= MOD;
                }
            }
        }

        /*
        cout << "deb " << i << "\n";
        cout << "0: \n";
        for(int i = 0; i < D; ++i){
            cout << dp1[i][0] << " ";
        }
        cout << "\n";
        cout << "1: \n";
        for(int i = 0; i < D; ++i){
            cout << dp1[i][1] << " ";
        }
        cout << "\n";
         */

        for(int k = 0; k < D; k++){
            for(int b = 0; b <= 1; b++){
                dp[k][b] = dp1[k][b];
                dp1[k][b] = 0;
                //cout << dp1[k][b] << ' ';
            }
        }
    }

    int ans = dp[0][0] - 1;
    ans += MOD;
    ans %= MOD;
    cout << (ans);
}

int main() {
    //std::ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int T = 1;

    //cin >> T;

    int i = 1;
    while(T--){
        solve();
        i++;
    }


    return 0;
}


#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#include <list>
#include <cassert>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

int Nctoi(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    else {
        return 0;
    }
}

int main() {
    string s; cin >> s;
    int M = s.size();
    int K; cin >> K;
    
    //前処理
    vector<vector<vector<ll>>> dp(M, vector<vector<ll>>(10, vector<ll>(K+1)));
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            dp[0][i][0] = 1;
        }
        else {
            dp[0][i][1] = 1;
        }
    }

    for (int d = 1; d < M; d++) {
        //d桁目を考える際はd-1桁目を見る
        for (int k = 0; k <= K; k++) {
            //impurityの数
            for (int top = 0; top < 10; top++) {
                //最上位桁の値をtopとする
                for (int ptop = 0; ptop < 10; ptop++) {
                    if (top == 0) {
                        dp[d][top][k] += dp[d - 1][ptop][k];
                    }
                    else {
                        if (k > 0) {
                            dp[d][top][k] += dp[d - 1][ptop][k - 1];
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        int cur = Nctoi(s[i]);
        if (i == 0 && M != 1) {
            for (int top = 0; top < cur; top++) ans += dp[M-i-1][top][K];
        }
        else if (i == M - 1 || M == 1) {
            for (int top = 0; top <= cur; top++) ans += dp[M-i-1][top][K];
        }
        else {
            for (int top = 0; top < cur; top++) ans += dp[M-i-1][top][K];
        }
        if (cur > 0) K--;
        if (K < 0) break;
    }
    cout << ans << endl;
}
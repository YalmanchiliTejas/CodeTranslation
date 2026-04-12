//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <vector <ll>> matrix;

#define endl "\n"
#define mt make_tuple
#define mp make_pair

template <typename T1, typename T2>
bool umax(T1 &a, const T2&b) { return a < b ? a = b, 1 : 0;}
template <typename T1, typename T2> 
bool umin(T1 &a, const T2 &b) {return a > b ? a = b, 1 : 0;}
template <typename T>
T sqr(T a) {return a * a;}
const int mod = 1000000007;
template <typename T1, typename T2>
void modadd(T1 &a, const T2 &b) {
    a += b;
    
    if (a >= mod)
        a -= mod;
}

mt19937 rng(20010709);
const int INF = 1000000001;
const int N = 1 << 21;

int d;
string K;
vector <int> k;
int dp[100005][105][2];

int f(vector <int> n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> d;

    for (int i = K.size() - 1; i > -1; i--)
        k.push_back(K[i] - '0');

    cout << f(k) << endl;

    return 0;
}

int f(vector <int> n) {
    fill(dp[0][0], dp[n.size()][d - 1] + 2, 0);

    for (int i = 1; i < n.back(); i++) {
        modadd(dp[n.size() - 1][i % d][0], 1);
    }

    modadd(dp[n.size() - 1][n.back() % d][1], 1);

    for (int i = n.size() - 2; i > -1; i--) {
        for (int cur = 1; cur < 10; cur++)
            modadd(dp[i][cur % d][0], 1);

        for (int cur = 0; cur < 10; cur++) {
            for (int pr = 0; pr < d; pr++)
                modadd(dp[i][(cur + pr) % d][0], dp[i + 1][pr][0]);
        }

        for (int pr = 0; pr < d; pr++) {
            modadd(dp[i][(pr + n[i]) % d][1], dp[i + 1][pr][1]);

            for (int cur = 0; cur < n[i]; cur++)
                modadd(dp[i][(cur + pr) % d][0], dp[i + 1][pr][1]);
        }
    }

    int result = 0;
    modadd(result, dp[0][0][0]);
    modadd(result, dp[0][0][1]);

    return result;
}
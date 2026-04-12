//
// Created by Hideaki Imamura on 2020-03-21.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
//const ll mod = 1000000007;

ll comb(ll N, ll R) {
    if (R < 0 || R > N) return 0;
    if (R == 1) return N;
    if (R == 2) return N * (N-1) / 2;
    return N * (N - 1) * (N - 2) / 6;
}

ll pow(ll N, ll k) {
    ll res = 1;
    for (int i = 0; i < k; ++k) res *= N;
    return res;
}

string S;
int N, K;

// solve(i, k, smaller) = i桁目以降についてみる。0以外の値を残りk回使用できる。i桁目までの値がSと等しいなら
// smaller = trueで、strictに小さいならsmaller = falseである。この時の場合の数。
ll solve(int i, int k, bool smaller) {
    if (i == N) return k == 0 ? 1 : 0;
    if (k == 0) return 1;
    if (smaller) return comb(N - i, k) * pow(9, k);
    if (S[i] == '0') return solve(i + 1, k, false);
    ll zero = solve(i + 1, k, true);
    ll aida = solve(i + 1, k - 1, true) * (S[i] - '1');
    ll ichi = solve(i + 1, k - 1, false);
    return zero + aida + ichi;
}

int main() {
    cin >> S >> K;
    N = S.size();
    cout << solve(0, K, false) << endl;
}
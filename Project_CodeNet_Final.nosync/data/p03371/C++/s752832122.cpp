//
// Created by Hideaki Imamura on 2020-03-30.
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

int A, B, C, X, Y;

int main() {
    cin >> A >> B >> C >> X >> Y;
    int ans = INF;
    for (int z = 0; z <= X + Y; ++z) {
        ans = min(ans, 2 * C * z + A * max(0, X - z) + B * max(0, Y - z));
    }
    cout << ans << endl;
    return 0;
}
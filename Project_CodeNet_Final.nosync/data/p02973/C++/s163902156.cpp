//
// Created by Hideaki Imamura on 2020-03-25.
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

int N;
vector<ll> A;

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    multiset<ll> m;
    for (int i = 0; i < N; ++i) {
        auto itr = m.lower_bound(A[i]);
        if (itr != m.begin()) m.erase(--itr);
        m.insert(A[i]);
    }
    cout << m.size() << endl;
    return 0;
}
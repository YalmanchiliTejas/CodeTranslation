#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = 1; i <= n; i++)
#define drep(i, n) for(int i = n-1; i >= 0; i--)
#define srep(i, s, t) for (int i = s; i < t; i++)
#define vi vector<int>
#define P pair<ll, ll>
using namespace std;
int mod = 1'000'000'000 + 7;
struct edge {
    int to;
    ll cost;
};

void COME_LET_THE_GAMES_BEGIN() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
}

int main() {
    COME_LET_THE_GAMES_BEGIN();
    int N, K;
    string S;
    cin >> N >> S >> K;
    rep(i, N) {
        if (S[i] != S[K - 1]) {
            S[i] = '*';
        }
    }
    cout << S << endl;
}
#include <bits/stdc++.h>

using namespace std;

#define fore(i, s, e) for(int i = s; i < e; i++)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;

const int N = 2e4;
const int M = 1e9 + 7;

string s;

int n, d;

ll dp[N][200][2];


ll calc(int i, int j, int k) {
    if(i == n && j == 0) return 1;
    if(i == n) return 0;
    ll &r = dp[i][j][k];
    if(r != -1) return r;
    ll times = 0;
    if(k) fore(dig, 0, s[i] - '0' + 1) {
        times += calc(i + 1, (j + dig) % d, (dig == (s[i] - '0')));
        times %= M;
    } else fore(dig, 0, 10) {
        times += calc(i + 1, (j + dig) % d, 0);
        times %= M;
    }
    return r = times % M;
}

int main() {
    s.resize(N);
    cin >> s;
    n = s.size();
    cin >> d;
    memset(dp, -1, sizeof dp);
    cout << (calc(0, 0, 1) + M - 1) % M << endl;
}
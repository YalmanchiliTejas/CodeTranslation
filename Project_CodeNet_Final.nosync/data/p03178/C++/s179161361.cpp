#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int M = 100 + 5;
ll dp[N][M][3];
const ll mod = 1e9 + 7;
string num;
int d;
void add_Self(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int solve(int idx, int m, int la) {
    if (idx == num.size())
        return !m && la < 2;
    if (dp[idx][m][la] != -1)
        return dp[idx][m][la];
    int res = !m;
    for (int i = 0; i < 10; i++) {
        int tempm = m + i;
        int nxt = la;
        if (la == 0) {
            if (i == (num[idx] - '0'))
                nxt = 0;
            if (i < (num[idx] - '0'))
                nxt = 1;
            if (i > (num[idx] - '0'))
                nxt = 2;
        }
        add_Self(res, solve(idx + 1, tempm % d, nxt));
    }
    return dp[idx][m][la] = res;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> num >> d;
    memset(dp, -1, sizeof dp);
    int res = 0;
    for (int i = 1; i < 10; i++) {
        int nxt = 0;
        if (i < (num[0] - '0'))
            nxt = 1;
        if (i > (num[0] - '0'))
            nxt = 2;
        add_Self(res, solve(1, i % d, nxt));
    }
    cout << res;
    return 0;
}

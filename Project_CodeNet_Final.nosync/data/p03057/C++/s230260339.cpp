#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << (a) << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;

vi split(string s) {
    vi ans;
    char last = 'X'; 
    s += 'X';
    int streak = 0;
    for (char c : s) {
        if (c != last) {
            if (streak) ans.pb(streak);
            streak = 0;
            last = c;
        }
        streak++;
    }
    return ans;
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

vi go(int n, int lim, int start) {
    vi dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        if (i >= start) add(dp[i], dp[i-start]);
        if (i >= lim+1) add(dp[i], MOD-dp[i-lim-1]);
        add(dp[i], dp[i-1]);
    }
    for (int i = n; i >= 1; i--) add(dp[i], MOD-dp[i-1]);
    return dp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,l;
    string s;
    cin >> n >> l >> s;
    auto p = split(s);
    if (si(p) == 1) {
        auto dp = go(n,n,2);
        int ans = 0;
        for (int dif = 1; dif <= n; dif++) {
            if (dif == 1 || dif == n-1) continue;
            add(ans, ll(dif) * dp[n-dif] % MOD);
        }
        cout << (ans+1)%MOD << endl;
    }
    else {
        if (n%2 == 1) {
            cout << 0 << endl;
        }
        else {
            int lim = p[0]/2+1;
            forn(i,si(p)) if (i%2 == 0 && p[i]%2 == 1 && i+1 != si(p)) 
                lim = min(lim, p[i]/2+1);
            n /= 2;
            auto dp = go(n, lim, 1);
            int ans = 0;
            for (int dif = 1; dif <= lim; dif++)
                add(ans, ll(dif) * dp[n-dif] % MOD);
            cout << 2LL*ans%MOD << endl;
        }
    }

    return 0;
}

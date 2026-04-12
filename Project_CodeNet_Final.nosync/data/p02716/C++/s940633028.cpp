#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef pair<int, int> pii;

// borrowed from neal's code
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n + 1);
    vector<ll> ps(n + 1, 0);
    vector<ll> dp(n + 1, 0); // dp[i] = choose floor(i / 2) with greatest sum among first i elements

    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    ps[1] = a[1];
    for (int i = 2; i <= n; ++i) 
    	ps[i] = ps[i - 2] + a[i];

    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
    	if (i & 1) {
    		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    	} else {
    		dp[i] = max(dp[i - 2] + a[i], ps[i - 1]);
    	}
    }

    cout << dp[n] << "\n";
}
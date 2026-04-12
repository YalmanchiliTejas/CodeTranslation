#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head
void add(int& a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int d;
    cin >> d;

    int n = s.size();
    vector<vi> dp(d, vi(2)); // # of ways so far
    dp[0][0] = 1;
    rep(digit,0,n) { // for each nxt digit
        vector<vi> cnt(d, vi(2));
        rep(i,0,d) {
            for(bool seenSmaller : {false, true}) {
                rep(j,0,10) {
                    if(j > (s[digit] - '0') && !seenSmaller) {
                        break;
                    } else {
                        add(cnt[(i + j) % d][seenSmaller || (j < (s[digit] - '0'))], dp[i][seenSmaller]);
                    }
                }
            }
        }
        dp = cnt;
    }
    int ans = (dp[0][0] + dp[0][1]) % mod;
    ans--;
    if(ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}

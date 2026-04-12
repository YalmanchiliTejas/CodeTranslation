#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;
ll const MOD = 1000000007;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int n;
cin >> n;
vector<string> S(n);
set <char> st;
rep(i,n) {
    cin >> S[i];
    int len = S[i].size();
    rep(j,len) {
        st.insert(S[i][j]);
    }
}

vector<char> ans;

for(auto c : st) {
    int cnt = INF;
    rep(i,n) {
        int cur = 0;
        rep(j,S[i].size()) {
            if(S[i][j] == c) cur++;
        }
        cnt = min(cnt,cur);
    }
    rep(i,cnt) ans.push_back(c);
}

sort(all(ans));
rep(i,ans.size()) {
    cout << ans[i];
}

cout << "\n";

return 0;
}
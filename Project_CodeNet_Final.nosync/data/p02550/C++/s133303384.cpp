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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x, m;
    cin >> n >> x >> m;

    // generate the sequence until a cycle is found 
    // profit?

    ll curr = x;
    ll ans = 0;
    vector<bool> vis(m + 1);
    vector<ll> s; // stack
    vector<ll> repeated;
    int cnt = 1; // current term
    while(cnt <= n) {
        if(!vis[curr]) {
            vis[curr] = true;
            s.pb(curr);
            ans += curr;
            curr = curr * curr % m; 
        } else {
            while(s.back() != curr) {
                repeated.pb(s.back());
                s.pop_back();
            }
            repeated.pb(s.back());
            break;
        }
        cnt++;
    }
    cnt--;
    reverse(all(repeated));

    n -= cnt;
    // for the remainder find the cycle
    if(n > 0) {
        ll cyclen = repeated.size();
        ll times = n / cyclen;
        ll ex = n % cyclen;
        for(int i = 0; i < repeated.size(); i++) {
            ans += repeated[i] * times;
            if(i < ex) {
                ans += repeated[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}

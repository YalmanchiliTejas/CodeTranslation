#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Rep(n) for (ll _ = 0; _ < (ll)(n); _++)

template<class S>S sum(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}
ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
ll min(int a,ll b){return min((ll)a,b);} ll min(ll a,int b){return min(a,(ll)b);}

#define PRINT_VECTOR_MAX 100
template <class S> void print(vector<S> &v){for(ll i=0; i<(ll)min(v.size(),PRINT_VECTOR_MAX); i++){cerr << v[i] << ' ';}cerr << endl;}
template <class S> void print(vector<vector<S>> &v) {for (ll i = 0; i < (ll)min(v.size(),PRINT_VECTOR_MAX); i++) {for (ll j = 0; j < (ll)min(v[i].size(),PRINT_VECTOR_MAX); j++) {cerr << v[i][j] << ' ';}cerr << endl;}}

void Main();
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	Main();
	return 0;
}

int mod;
struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

void Main(){
    ll n;
    ll x,m; cin >> n >> x >> m;
    vector<ll> memo(m, 0);
    vector<ll> ss(m, 0);
    memo[x] = 1;
    ss[x] = 0;
    ll now = x;
    ll cnt = 1;
    unsigned long long ans = x;
    while(1){
        if(cnt == n){
            cout << ans << endl;
            return;
        }
        
        now = (now * now) % m;
        cnt++;

        
        
        
        if(memo[now]){
            ll loop = cnt - memo[now];
            ll nloop = (n - cnt + 1) / loop;

            ans += nloop * (ans - ss[now]);
            cnt += nloop * loop;
            break;
        }
        ss[now] = ans;
        ans += now;
        memo[now] = cnt;
        
    }
    for(; cnt <= n; cnt++){
        ans += now;
        now = (now * now) % m;
        

    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
struct INF { template<class T> operator T() { return numeric_limits<T>::max() / 2; } } INF;


int main(){

    ll n, x, m;
    cin >> n >> x >> m;

    V<ll> t;
    set<ll> st;
    t.push_back(x);
    st.insert(x);

    int cnt = 1;
    ll last = 0;
    for(;;) {
        ll a = t.back();
        last = a*a % m;
        if(st.find(last) != st.end()) {
            break;
        }
        else {
            cnt++;
            t.push_back(last);
            st.insert(last);
        }
    }

    V<ll> sums(cnt+1);
    int idx = 0;
    Rep(i,cnt) {
        if(t[i-1] == last) idx = i;
        sums[i] = sums[i-1] + t[i-1];
    }

    idx--;
    if(n <= cnt) {
        cout << sums[n] << endl;
    }
    else {
        n -= idx;
        ll roop = sums[cnt] - sums[idx];
        ll ans = n / (cnt-idx) * roop;
        ans += sums[n % (cnt-idx) + idx];

        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define ll long long
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (ll i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define pr(s) cout << (s) << '\n'
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;
const ll INFll = 1E+18;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> v(m);
    rep(i, m) {
        v[i] = ((ll)i*i)%m;
        //debug(v[i]);
    }
    
    ll xx = x;
    ll s = 0;
    ll index = 0;
    while (1) {
        s += xx;
        xx = v[xx];
        index++;
        if (xx==0) {
            pr(s);
            return 0;
        }
        if (index==n) {
            pr(s);
            return 0;
        }
        if (index==m+5) break;
    }
    
    
    vector<bool> used(m);
    ll loop = 0;
    ll now = x;
    ll sum_loop = 0;
    ll ans = 0;
    ll start = 0;
    //return 0;
    while (1) {
        used[now] = true;
        now = v[now];
        if (used[now]) {
            start = now;
            break;
        }
    }
    now = x;
    while (1) {
        ans += now;
        now = v[now];
        n--;
        if (now==start) break;
    }
    now = start;
    while (1) {
        loop++;
        sum_loop += now;
        now = v[now];
        if (now==start) break;
    }
    //debug(loop);
    ll z = n/loop;
    
    ans += z*sum_loop;
    n %= loop;
    now = start;
    rep(i, n) {
        ans += now;
        now = v[now];
        //debug(ans);
    }

    
    
    pr(ans);
    return 0;
}
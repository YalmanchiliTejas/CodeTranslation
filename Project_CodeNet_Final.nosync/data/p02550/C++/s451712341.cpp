#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FOREACH(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define SIZE(v) ((int)(v).size())
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define ll long long
#define llint long long
#define pii pair<int, int>
#define UNVISITED -1


template<typename T>
string to_string(const vector<T>& vc, int w) {
	if(vc.empty()) return "";
	if(w + 1 == vc.size()) return to_string(vc[w]);
	return to_string(vc[w]) + "," + to_string(vc, w + 1);
}
 
template<typename T>
string to_string(const vector<T>& vc) {
	return "{" + to_string(vc, 0) + "}";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

ll M;

ll f(ll x) {
    return (x*x)%M;
}

pii floyd(int x0) {
    int t = f(x0), h = f(f(x0));
    while(t != h) {
        t = f(t);
        h = f(f(h));
    }
    int mu = 0; h = x0;
    while(t != h) {
        t = f(t);
        h = f(h);
        mu++;
    }
    int lambda = 1; h = f(t);
    while(t != h) {
        h = f(h);
        lambda++;
    }
    return mp(mu, lambda);
}

int main() {
    ll N, X;
    scanf("%lld %lld %lld", &N, &X, &M);
    pii tmp = floyd(X);
    int mu = tmp.first, lambda = tmp.second;

    ll ans = 0;
    ll x = X;
    REP(i, mu) {
        if(N == 0) break;
        ans += x;
        x = f(x);
        N--;
    }

    vector<ll> data, acc;
    data.pb(0);
    acc.pb(0);
    REP(i, lambda) {
        data.pb(x);
        acc.pb(acc.back() + data.back());
        x = f(x);
    }

    ll c = N / lambda;
    N %= lambda;
    ans += c * acc[lambda] + acc[N];
    printf("%lld\n", ans);

}
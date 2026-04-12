#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 4000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};

class mint {
    long long x;
public:
    mint(long long x = 0) : x((x% MOD + MOD) % MOD) {}
    mint operator-() const {
        return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res *= a;
    }

    mint operator^(const ll& t)const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return pow(MOD - 2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res /= a;
    }

    friend ostream& operator<<(ostream& os, const mint& m) {
        os << m.x;
        return os;
    }
};

//////////////////////////


struct dijkstra {

    ll N;
    vector<vector<edge>> g;
    ll s;

    vector<ll> ans;

    dijkstra(ll N0, ll s, vector<vector<edge>> g0) {//頂点数、始点、グラフ(頂点は1indexか0index)
        N = N0;
        g = g0;

        ans.assign(N + 1, INF);


        priority_queue<pair<ll, ll>> q;//(-キョリ、頂点)

        ans[s] = 0;
        q.push({ 0,s });

        while (!q.empty()) {
            auto x = q.top();
            q.pop();

            ll dis = -x.first;
            ll v = x.second;

            if (dis > ans[v]) { continue; }


            for (edge e : g[v]) {
                ll w = e.to;
                if (dis + e.d < ans[w]) {
                    ans[w] = dis + e.d;
                    q.push({ -ans[w], w });
                }
            }


        }
    }

    ll d(ll t) {//sからtまでの最短距離を出力
        return ans[t];
    }


};

void nm(ll N, ll s, vector<vector<edge>> g, vector<ll> d, vector<mint>& n) {
    vector<pair<ll, ll>> p(N + 1);
    repn(i, N)p[i] = { d[i],i };
    sort(++p.begin(), p.end());

    n[s] = 1;
    repn(i, N) {
        ll v = p[i].second;
        for (edge e : g[v]) {
            ll w = e.to;
            if (d[w] == d[v] + e.d) { n[w] += n[v]; }
        }
    }
}

int main() {
    
    ll N, M, S, T;
    cin >> N >> M >> S >> T;

    vector<vector<edge>> g(N + 1);
    repn(i, M) {
        ll u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({ i,u,v,d });
        g[v].push_back({ i,v,u,d });
    }

    dijkstra ds(N, S, g);
    dijkstra dt(N, T, g);

    vector<mint> ns(N + 1, 0);
    vector<mint> nt(N + 1, 0);

   
    nm(N, S, g, ds.ans, ns);
    nm(N, T, g, dt.ans, nt);

    ll D = ds.ans[T];
    mint K = ns[T];

    mint ans = K * K;

    repn(v, N) {
        if (ds.ans[v] * 2 == D && dt.ans[v] * 2 == D) {
            ans -= ns[v] * nt[v] * ns[v] * nt[v];
        }
        for (edge e : g[v]) {
            ll w = e.to;
            if (ds.ans[v] * 2 < D && dt.ans[w] * 2 < D && ds.ans[v] + e.d + dt.ans[w] == D) {
                ans -= ns[v] * nt[w] * ns[v] * nt[w];
            }
        }
    }

    cout << ans;

    

	system("PAUSE");
}
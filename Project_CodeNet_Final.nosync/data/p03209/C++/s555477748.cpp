#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(ll i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(ll i=(begin)-1;i>=(end);i--)
#define IREP(i, n) IFOR(i,n,0)
#define SORT(a) sort(a.begin(), a.end())
#define ISORT(a) sort(a.begin(), a.end(),greater<ll>())
#define REVERSE(a) reverse(a.begin(), a.end())
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=("; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << ")" << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;}
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)

#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define INF 1000000000000000000

using vec = vector<ll>;
using mat = vector<vec>;
using Pii = pair<ll, ll>;
using PiP = pair<ll, Pii>;
using PPi = pair<Pii, ll>;
using bvec = vector<bool>;
using Pvec = vector<Pii>;


template<typename T> void readv(vector<T> &a) { REP(i, a.size()) cin >> a[i]; }
void readv_m1(vector<int> &a) { REP(i, a.size()) {cin >> a[i]; a[i]--;} }

ll mod = 1000000007;

int main()
{
    ll N, X;
    cin >> N >> X;
    ll ans = 0;
    vec T(N), P(N);
    T[0] = 1;
    P[0] = 1;
    FOR(i, 1, N) {
        T[i] = T[i - 1] * 2 + 3;
        P[i] = P[i - 1] * 2 + 1;
    }

    while (X > 0) {
        if (N == 1) {
            ans += max((ll)0, min(X - 1, (ll)3));
            break;
        }
        else if (X >= 2 + T[N - 1]) {
            ans += P[N - 1] + 1;
            X -= 2 + T[N - 1];
            N--;
        }
        else if (X >= 1 + T[N - 1]) {
            ans += P[N - 1];
            X -= 1 + T[N - 1];
            N--;
        } else {
            X--;
            N--;
        }
    }

    cout << ans << endl;

    return 0;
}
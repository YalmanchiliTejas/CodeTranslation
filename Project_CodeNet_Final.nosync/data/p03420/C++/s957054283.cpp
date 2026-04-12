#include<bits/stdc++.h> 
#define REP(i, b) for(int i = 0; i < (b); i++)
#define REPS(i, b) for(int i = 1; i <= (b); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;
const int INF = 1e9;
const int MOD = 1e9+7;


signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll N, K; cin >> N >> K;
    ll ans = 0;
    if(K == 0)
    {
        cout << N*N << endl;
        return 0;
    }
    for(ll b = 1; b <= N; b++)
    {
        ll p = N/b;
        ans += p * max((ll)0, b-K);
        ans += max((ll)0, N%b-K+1);
    }
    cout << ans << endl;
}
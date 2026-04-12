#include<bits/stdc++.h> 
#define REP(i, b) for(int i = 0; i < (b); i++)
#define REPS(i, b) for(int i = 1; i <= (b); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
const int INF = 1e9;

ll N, X;
vl a(51), p(51);

ll eat(ll n, ll x)
{
    if(n == 0)
    {
        if(x <= 0) return 0;
        return 1;
    }
    else if(x <= 1 + a[n-1]) return eat(n-1, x-1);
    else return p[n-1]+1+eat(n-1, x-2-a[n-1]);
}

signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> X;
    a[0] = 1; p[0] = 1;
    REPS(i, 50)
    {
        a[i] = 2*a[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }
    cout << eat(N, X) << endl;
}
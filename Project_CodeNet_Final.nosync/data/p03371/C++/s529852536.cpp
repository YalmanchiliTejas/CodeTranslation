#include <bits/stdc++.h>

#define PI 3.1415926535897932
#define MOD 1000000007
#define INF 1e9

#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, start, end) for(int i = (start); i < (end); i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;


void solve()
{
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if(A + B > 2*C)
    {
        int n = min(X, Y);
        ans += n * 2*C;
        X -= n;
        Y -= n;
    }
    ans += min(A, 2*C) * X;
    ans += min(B, 2*C) * Y;
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
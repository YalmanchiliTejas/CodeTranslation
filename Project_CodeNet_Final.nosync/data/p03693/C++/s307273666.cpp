#include <bits/stdc++.h>

#define PI 3.1415926535897932
#define MOD 1000000007
#define INF 2e9

#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, start, end) for(int i = (start); i < (end); i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;


void solve()
{
    int r, g, b; cin >> r >> g >> b;
    int num = 100 * r + 10 * g + b;
    if(num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();

    return 0;
}
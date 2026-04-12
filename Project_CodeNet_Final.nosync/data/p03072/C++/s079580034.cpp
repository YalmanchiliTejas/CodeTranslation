#include <bits/stdc++.h>

#define PI 3.1415926535897932
#define MOD 1000000007
#define INF 1e9

#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define ALL(v) (v).begin(), (v).end()
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO  cout << "NO"  << endl
#define No  cout << "No"  << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;


void solve()
{
    int N; cin >> N;
    vi H(N); REP(i, N) cin >> H[i];
    int ans = 0, m = -INF;
    REP(i, N)
    {
        if(m <= H[i]) ans++;
        m = max(m, H[i]);
    }
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
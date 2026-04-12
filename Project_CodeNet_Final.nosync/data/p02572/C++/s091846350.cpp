#include <bits/stdc++.h>

/*                     
*/

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ins insert
#define mp make_pair
#define len(s) s.length()
#define forp(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define ren(i, n) for (int i = n - 1; i >= 0; i--)
#define forn(i, a, b) for (int i = a; i >= b; i--)
#define on cout << endl
#define o2(a, b) cout << a << " " << b
#define os cout << " "
#define all(v) v.begin(), v.end()
#define mem(n, m) memset(n, m, sizeof(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define sii set<int>
#define us unordered_set<int>
#define um unordered_map<int, int>
#define sll set<long long>
#define vii vector<int>
#define vll vector<long long>
#define mll map<long long, long long>
#define lob lower_bound
#define upb upper_bound
#define ret return 0
#define present(s, x) (s.find(x) != s.end())
#define cpresent(s, x) (find(all(s), x) != s.end())
#define ford(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define fors(container, it, a, b) for (__typeof(container.begin()) it = a; it != b; it++)

#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define inf 999999999999999999
#define siz 100001
#define SIZ 1000001
#define SIZE 200001

typedef long long ll;
typedef long double ldo;
typedef double db;
using namespace std;
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

//Everything is temporary...So,enjoy little things...
void c_p_c()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    c_p_c();
    ll n;
    cin >> n;
    ll a;
    ll sum = 0, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a;
        if (i)
        {
            ans = (ans + ((sum * a) % MOD)) % MOD;
        }
        sum = (sum + a) % MOD;
    }
    cout << ans << endl;
    return 0;
}
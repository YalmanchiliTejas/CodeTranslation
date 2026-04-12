#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(n) FOR(O, 1, (n))
#define pb push_back
#define f first
#define s second
#define INF 1e9+1
#define PI 3.1415926535897932846
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<piiii> viiii;
typedef vector<pll> vll;
typedef vector<pld> vld;

const int MAXN = 100100;
const ll MOD = 1e9+7;

int n;
int a[MAXN];

int main()
{
    FAST_IO;

    cin >> n;
    FOR(i, 0, n-1) cin >> a[i];
    vi k;
    k.pb(-1);

    FOR(i, 0, n-1) {
        if (a[i] <= k[k.size()-1]) k.pb(a[i]);
        else {
            int le = 0, ri = k.size()-1;
            while (le < ri) {
                int mid = (le+ri)/2;
                if (a[i] > k[mid]) ri = mid;
                else le = mid + 1;
            }
            k[le] = a[i];
        }
    }

    cout << k.size() << endl;

    return 0;
}

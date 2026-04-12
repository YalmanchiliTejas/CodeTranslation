#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < n; i++)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> H(N);
    rep (i, N) {
        cin >> H[i];
    }

    int ans = 0;
    for (int i = N; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (H[i-1] < H[j]) {
                break;
            }
            if (j == i-1) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
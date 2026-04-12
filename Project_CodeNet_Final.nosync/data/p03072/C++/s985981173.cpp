#include <bits/stdc++.h>

#define SYNC ios::sync_with_stdio(0);
#define F first
#define S second
#define endl '\n'


using namespace std;

using ll = long long int;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;
using graph = vector<vi>;
const int INF = 0x3f3f3f3f;
const int MAXN = 58;
const ll mod = 1000000007;



int main() {
    SYNC
    int n;
    cin >> n;
    int ans = 1, inn;
    cin >> inn;
    int maxi = inn;
    int a;
    for (int i = 1; i < n; ++i) {
        cin >> a;
        if (a >= inn && a >= maxi) {
            ans++;
        }
        maxi = max(a, maxi);
    }
    cout << ans << endl;
    return 0;
}
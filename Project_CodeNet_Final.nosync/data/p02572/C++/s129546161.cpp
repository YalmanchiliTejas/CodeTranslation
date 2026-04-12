#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep01(i, n) for(int i = 0; i < (n) + 1; i++)
#define rep10(i, n) for(int i = 1; i < (n); i++)
#define rep11(i, n) for(int i = 1; i < (n) + 1; i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
typedef struct { int x; int y; } Pos;
using namespace std;


int main()
{
    int sum = 0;
    ll ans = 0;
    const int MOD = 1000000007;

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }

    rep(i, n) {
        sum -= a[i];
        if (0 > sum) sum += MOD;
        ans += a[i] * (ll)sum;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
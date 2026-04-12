#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007

int main()
{
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll i = K + 1; i <= N; i++)
    {
        ll t = ((N - K) / i);
        ll s = t * (i - K);
        s += min(N + 1, (t + 1) * i) - (K + t * i);
        if (K == 0)
            s--;
        ans += s;
    }
    cout << ans << endl;
}
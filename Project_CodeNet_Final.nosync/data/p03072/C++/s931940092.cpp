#include <iostream>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef long long int ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define print(x) cout << x << endl

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> H(N);
    rep(i, N) cin >> H[i];
    ll ma = 0;
    ll cnt = 0;
    rep(i, N)
    {
        if (ma <= H[i]) {
            cnt++;
            ma = H[i];
        }
    }
    print(cnt);
    return 0;
}

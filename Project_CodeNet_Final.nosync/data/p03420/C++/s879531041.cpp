#include <bits/stdc++.h>
/*
#include<algorithm>
#include<array>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<typeinfo>
#include<utility>
#include<vector>
*/
#define int long long int
#define double long double
using namespace std;
#define INT_DMAX 1000000007
#define INF 1000000000000000007
const int MAX_N = 1 << 17;
#define rep(i, n) for (int(i) = 0, i##_len = (n); (i) < i##_len; (i)++)
#define reps(i, x) for (int(i) = 1; (i) <= (int)(x); (i)++)
#define rrep(i, x) for (int(i) = ((int)(x)-1); (i) >= 0; (i)--)
#define rreps(i, x) for (int(i) = ((int)(x)); (i) > 0; (i)--)
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define mp make_pair
#define bit(n) ((int)(1) << (n))
#define all(x) (x).begin(), (x).end()
#define debug(x) std::cout << #x << ": " << (x) << std::endl
#define nint int
using namespace std;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};
typedef pair<int, int> pii;
typedef pair<double, double> dop;
template <class T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b)
{
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
struct aaa {
    aaa()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} aaaaaaa;


signed main()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int b = 1; b <= n; b++) {
        if (b - k <= 0)
            continue;
        sum += (n / b) * (b - k);
        sum += max((int)0, n % b - k + 1);
    }
    if (k == 0) {
        sum -= n;
    }
    cout << sum << endl;
    return 0;
}
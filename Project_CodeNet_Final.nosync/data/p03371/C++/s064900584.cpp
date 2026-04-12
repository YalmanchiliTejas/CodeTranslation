#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll sum1 = A * X + B * Y;
    ll sum2 = max(X, Y) * 2 * C;
    ll sum3;
    if (X < Y)
    {
        sum3 = X * 2 * C + (Y - X) * B;
    }
    else
    {
        sum3 = Y * 2 * C + (X - Y) * A;
    }

    cout << min(min(sum1, sum2), sum3) << endl;
}
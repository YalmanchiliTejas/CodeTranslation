#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <queue>
using namespace std;
const int INT_INF = 500000000;
const long long LONG_LONG_INF = (long long)pow(10, 18);
const int MOD = pow(10, 9) + 7;
/* contest template */
int N, K;
long long ans;

int main()
{
    cin >> N >> K;
    for (int b = K + 1; b <= N; b++)
    {
        ans += (b - K) * (N / b);
        if (N % b >= K)
        {
            if (K != 0)
            {
                ans += (N % b) - (K - 1);
            }
            else
            {
                ans += N % b;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
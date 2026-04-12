#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    vector<int> xs(N); for (auto &xi : xs) cin >> xi;
    vector<int> sorted = xs;
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i <= N; ++i)
    {
        if (xs[i - 1] < sorted[N / 2]) cout << sorted[N / 2] << endl;
        else cout << sorted[N / 2 - 1] << endl;
    }
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <deque>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;
using ld = long double;
using ll = long long;
using pii = pair<int, int>;

#define int int64_t
#define pb push_back
#define pbb pop_back
#define pf pop_front
#define pff push_front
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()

const int INF = 1e6, MOD = 1e9 + 7, MAXN = 1e5 + 7;
const ld EPS = 1e-9, PI = acos(-1);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pii> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(all(nums));
    vector<int> answer(n);
    for (int i = 0; i < n / 2; ++i)
        answer[nums[i].second] = nums[n / 2].first;
    for (int i = n / 2; i < n; ++i)
        answer[nums[i].second] = nums[n / 2 - 1].first;

    for (int elem : answer)
        cout << elem << "\n";

    return 0;
}

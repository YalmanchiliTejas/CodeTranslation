#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

LLONG times[50][2501];

int main()
{
    int N; cin >> N;    // N <= 1e5
    // 色ごとの最大値（実際には符号反転するので最小値）
    // ai = 0 が最小なので，反転を考慮し初期値は1とする
    // 色ごとの最大値をmultisetで管理し，新しい値を越えるもののうち
    // 最小の値を更新していく:O(NlogN)
    multiset<int> maxValues{ 1 };
    for (int i = 0; i < N; ++i)
    {
        int ai; cin >> ai;
        // upper_boud()を使うため符号反転する
        ai *= -1;
        auto itr = maxValues.upper_bound(ai);   // O(log(Size))
        if (itr == maxValues.end())
        {
            maxValues.insert(ai);   // O(log(Size))
        }
        else
        {
            maxValues.erase(itr);   // O(1)
            maxValues.insert(ai);   // O(log(Size))
        }
    }
    cout << maxValues.size() << endl;
}
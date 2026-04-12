#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    deque<int> d;
    rep(i, n) {
        int idx = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (idx == 0) {  // dの全ての要素がa[i]以上のとき、塗り分ける色(=dのサイズ)が増加
            d.push_front(a[i]);
        }
        else {  // dの要素の内、a[i]より小さい中で最大のものをa[i]に書き換える、塗り分ける色は増えない
            d[idx - 1] = a[i];
        }
    }
    cout << d.size() << endl;
    return 0;
}

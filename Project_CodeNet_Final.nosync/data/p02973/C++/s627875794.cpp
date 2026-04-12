#include <vector>
#include <iostream>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> arr;
    arr.reserve(100000);
    rep (i, n) {
        ll a;
        cin >> a;
        a = -a;
        if (arr.empty()) {
            arr.push_back(a);
            continue;
        }
        auto pos = upper_bound(arr.begin(), arr.end(), a); // a 以上の要素で最小

        if (pos == arr.end()) {
            arr.push_back(a);
        } else {
            *pos = a;
        }
    }
    cout << arr.size() << endl;
    return 0;
}

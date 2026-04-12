//Binary_search:二分探索法に依る検索
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vecll = vector<long long>;
#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)

int main()
{
    ll n, q, k;
    vecll a;

    cin >> n;
    a.resize(n);
    for (auto &x : a)
        cin >> x;

    cin >> q;
    rep(i, q)
    {
        cin >> k;
        cout << distance(a.begin(), lower_bound(all(a), k)) << endl;
    }

    return 0;
}

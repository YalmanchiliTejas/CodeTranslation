#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class InputIterator1, class InputIterator2>
ll f(ll N, InputIterator1 it1, InputIterator2 it2)
{
    auto first = *it1;
    auto last = *it1;
    ll res = 0;
    while (true) {
        res += abs(*it1 - last);
        last = *it1;
        it1++;
        N--;
        if (N == 1) {
            break;
        }
        res += abs(*it2 - last);
        last = *it2;
        it2++;
        N--;
        if (N == 1) {
            break;
        }
    }
    res += max(abs(first - *it1), abs(last - *it1));
    return res;
}

void main_()
{
    ll N;
    cin >> N;
    vector<ll> As;
    As.reserve(N);
    copy_n(istream_iterator<ll>(cin), N, back_inserter(As));

    sort(begin(As), end(As));

    ll ans = max(f(N, begin(As), rbegin(As)), f(N, rbegin(As), begin(As)));
    cout << ans << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}

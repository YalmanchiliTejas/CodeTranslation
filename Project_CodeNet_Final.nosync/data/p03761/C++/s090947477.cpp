#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void main_()
{
    ll n;
    cin >> n;

    string r;
    cin >> r;
    sort(begin(r), end(r));
    for (ll i = 1; i < n; ++i) {
        string S;
        cin >> S;
        sort(begin(S), end(S));
        string w;
        set_intersection(begin(S), end(S), begin(r), end(r), back_inserter(w));
        r = move(w);
    }
    cout << r << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main(void) {
    string s;
    cin >> s;
    ll a = count(begin(s), end(s), 'A');
    ll b = 3 - a;
    cout << ((!a || !b) ? "No" : "Yes") << endl;

    return 0;
}

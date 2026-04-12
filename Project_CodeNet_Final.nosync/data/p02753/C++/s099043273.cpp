#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)

using namespace std;

namespace mp = boost::multiprecision;

using ll = long long;
using ul = unsigned long long;
using Bint = mp::cpp_int;
ll mod = 1000000007;

int main() {
source:
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}


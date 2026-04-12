#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)

using namespace std;

namespace mp = boost::multiprecision;

using ll = long long;
using Bint = mp::cpp_int;
ll mod = pow(10, 9) + 7;

int main() {
    // source
    int n, m;
    cin >> n >> m;

    if (n == m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;

int main() {
    // input, ready
    string S;
    cin >> S;

    // output
    if (S[0] == S[1] && S[1] == S[2] ) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}

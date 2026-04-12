#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
using namespace std;
using boost::irange;

int main() {
    int N, M;
    cin >> N >> M;

    bool yes = N == M;
    cout << (yes ? "Yes" : "No") << '\n';
}

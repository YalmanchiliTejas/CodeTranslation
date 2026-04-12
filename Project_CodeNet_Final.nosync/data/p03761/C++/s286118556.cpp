#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;


int main() {
    ll n;
    cin >> n;
    vector<array<ll, 26>> alphabets(n, array<ll, 26>{});
    for (auto &&i: irange(0LL, n)){
        string s;
        cin >> s;
        for (auto &&c  : s) {
            alphabets.at(i).at(c-'a')++;
        }
    }
    array<ll, 26> minima{};
    minima.fill(numeric_limits<ll>::max());
    for (auto &&i: irange(0LL, n)){
        for (auto &&j: irange(0LL, 26LL)){
            minima.at(j) = min(minima.at(j), alphabets.at(i).at(j));
        }
    }

    for (auto &&i: irange(0LL, 26LL)){
        for (auto &&j: irange(0LL, minima.at(i))){
            cout << (char)('a'+i);
        }
    }
    cout << endl;

    return 0;
}
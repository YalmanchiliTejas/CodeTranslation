#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost::adaptors;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    ll N;
    cin >> N;
    vector<ll> xs(N, 0);
    for (auto &&i: boost::irange(0LL, N)){
        cin >> xs.at(i);
    }
    vector<ll> xs_original(xs.begin(), xs.end());
    sort(xs.begin(), xs.end());
    ll former = N / 2 - 1;
    ll latter = N / 2;
    ll threshold = (xs.at(former) + xs.at(latter)) / 2;
    for (auto &&i: boost::irange(0LL, N)){
        if (xs_original.at(i) <= threshold){
            cout << xs.at(latter) << endl;
        } else {
            cout << xs.at(former) << endl;
        }
    }
    return 0;
}
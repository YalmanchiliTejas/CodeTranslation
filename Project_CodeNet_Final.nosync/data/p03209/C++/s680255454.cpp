#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;

ll f(int n, ll x, vector<ll> &a, vector<ll> &p) {
    if (n == 0) {
        return 1;
    }
    if (x == 1) {
        return 0;
    }
    else if (x <= a.at(n-1)+1) {
        return f(n-1, x-1, a, p);
    }
    else if (x == a.at(n-1)+2) {
        return p.at(n-1)+1;
    }
    else if (x <= 2*a.at(n-1)+2) {
        return p.at(n-1) + 1 + f(n-1, x-2-a.at(n-1), a, p);
    }
    else {
        return 2*p.at(n-1)+1;
    }
}
 
int main() {
    int n = 0;
    ll x = 0;
    cin >> n >> x;
    vector<ll> a(n+1), p(n+1);
    a.at(0) = p.at(0) = 1;
    for (int i=1; i<n+1; i++) {
        a.at(i) = 2*a.at(i-1) + 3;
        p.at(i) = 2*p.at(i-1) + 1;
    }
    cout << f(n, x, a, p) << endl;
    return 0;
}
 
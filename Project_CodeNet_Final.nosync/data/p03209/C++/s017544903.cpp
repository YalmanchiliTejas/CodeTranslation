#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric>

typedef long long ll;
using namespace std;

ll patties(int n, ll x, vector<ll> &p, vector<ll> &pp) {
    if (x <= 0) return 0;
    if (n == 0) return x > 0;
    ll th = p[n] / 2;
    if (x >= p[n]) {
        return pp[n];
    } else if (x < th) {
        return patties(n - 1, x - 1, p, pp);
    } else if (x == th) {
        return pp[n-1];
    } if (x > th) {
        return pp[n-1] + 1 + patties(n - 1, x - th - 1, p, pp);
    }
}

int main() {
    
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> p(51, 1); // p[i] == things in a level-i burger
    vector<ll> pp(51, 1); // pp[i] == patties in a level-i burger
    for (int i = 1; i <= 50; i++) {
        p [i] = p [i-1] * 2 + 3;
        pp[i] = pp[i-1] * 2 + 1;
    }
    
    cout << patties(n, x, p, pp) << endl;
    
}
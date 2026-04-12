// Template
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>

using namespace std;
typedef long long ll;

#define REP(i, n) for(int i = 0;i < n;i++)
#define INF 1 << 30

int MOD = 1000000007;



int main(){
    std::ios_base::sync_with_stdio(false);

    int n; cin >>  n;
    std::vector<ll> x(n); REP(i,n) cin >> x[i];
    std::vector<ll> x_(n);
    x_ = x;
    sort(x.begin(), x.end());
    ll l = x[x.size()/2-1];
    ll u = x[x.size()/2];

    REP(i,n) x_[i] >= u ? cout << l << endl : cout << u << endl;



    return 0;
}

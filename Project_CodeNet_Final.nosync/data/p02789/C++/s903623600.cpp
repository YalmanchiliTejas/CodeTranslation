#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <mutex>
#include <cmath>
#include <set>
#include <climits>
#include <bitset>

#define mod 1e9+7
#define mp make_pair
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b;
    string ans = "No";
    cin >> n >> a;
    if(n == a) ans = "Yes";
    cout << ans;
    return 0;
}
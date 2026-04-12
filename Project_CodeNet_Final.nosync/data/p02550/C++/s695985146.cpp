#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
int main(){
    ll n;
    cin >> n;
    ll x, m;
    cin >> x >> m;
    ll ans = 0;
    rep(i,m){
        n--;
        ans += x;
        x = x * x % m;
        if(n==0){
            cout << ans << endl;
            return 0;
        }
    }
    vector<ll> a;
    a.push_back(x);
    if(x * x % m == x){
        cout << ans + n * x << endl;
        return 0;
    }
    while(1){
        ll t = a.back() * a.back() % m;
        if(t != x)a.push_back(t);
        else break;
    }
    ans += n/a.size() * accumulate(a.begin(), a.end(), 0LL);
    n %= a.size();
    while(n--){
        ans += x;
        x = x * x % m;
    }
    cout << ans << endl;
}

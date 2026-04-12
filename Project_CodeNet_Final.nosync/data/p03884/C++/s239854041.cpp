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
#include <unordered_set>
#include <unordered_map>
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
    string s = "FESTIVA";
    string t;
    const int sz = 600;
    rep(i,sz){
        t += s;
    }
    vector<ll>a(7);
    vector<ll>dp;
    rep(i,7*sz){
        rep(j,7)if(t[i] == s[j]){
            if(j)a[j] += a[j-1];
            else a[0]++;
        }
        if((i + 1) % 7 == 0){
            dp.push_back(a[6]);
        }
    }
    show(dp);
    ll k;
    cin >> k;
    vector<ll> c(sz);
    for(int i = sz - 1; i >= 0; i--){
        while(k - (c[i]+1)*dp[i]>=0){
            c[i]++;
        }
        k -= c[i] * dp[i];
    }
//    show(c);
    assert(k == 0);
    string ans;
    rep(i,sz){
        ans += s;
        ans += string(c[i],'L');
        cout << s << string(c[i],'L');
    }
    cout << endl;
    s += 'L';
    a.clear();
    a.resize(8);
    show(a);
    rep(i,ans.size()){
        rep(j,8)if(ans[i] == s[j]){
            if(j)a[j] += a[j-1];
            else a[0]++;
        }
//        show(i,a);
    }
    show(a);
}
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "]"; return os; }


// import here

int main(){
    LL n, k;
    cin >> n >> k;
    LL ans = 0;
    for(LL b = k+1; b <= n; ++b){
        LL cnt = n / b;
        ans += cnt * (b-k);
        ans += max<LL>(0, n - (cnt*b + k-1));
    }
    if(k == 0) ans = n*n;
    cout << ans << endl;
    return 0;
}


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
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "]"; return os; }



int main(){
    LL n;
    cin >> n;
    vector<LL> a(n);
    for(LL i = 0; i < n; ++i){
        cin >> a[i];
    }
    LL ans = 0;
    for(LL i = 1; i < n; ++i){
        LL part = 0;
        for(LL j = 1; j*i < n-1; ++j){
            LL left = j*i;
            LL right = n-1-j*i;
            if((n-1)%i==0 && left >= right) break;
            if(right < i) break;
            part += a[left] + a[right];
            //cerr << "i=" << i << ", " << part << endl;
            ans = max<LL>(ans, part);
        }
    }
    cout << ans << endl;
    return 0;
}


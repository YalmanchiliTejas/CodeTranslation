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
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "}"; return os; }


int main(){
    LL n;
    cin >> n;
    multiset<LL> a;
    for(LL i = 0; i < n; ++i){
        LL v;
        cin >> v;
        auto it = a.lower_bound(v);
        if(it != a.begin() && *(--it) < v){
            a.erase(it);
        }
        a.insert(v);
        //cerr << v << ", " << a.size() << endl;
    }
    cout << a.size() << endl;
    return 0;
}


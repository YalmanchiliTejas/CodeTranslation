#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
    return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
    int n; cin >> n;
    
    multiset<int> s;
    REP(i, n) {
        int a; cin >> a;
        auto it = s.lower_bound(a);
        
        if(it != s.begin() && *(--it) < a) {
            s.erase(it);
            s.insert(a);
        } else {
            s.insert(a);
        }
    }

    cout << s.size() << endl;

    return 0;
}

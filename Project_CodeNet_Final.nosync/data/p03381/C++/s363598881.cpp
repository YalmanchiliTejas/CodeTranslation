#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ in >> p.first >> p.second; return in; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }
template <char d = ' ', class T>
ostream& operator << (ostream& out, vector<T>& v){ for(auto& e : v){ out << e << d; } return out; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> xs(n); cin >> xs;
    auto x2 = xs;
    sort(x2.begin(), x2.end());
    int n1 = x2[n / 2 - 1], n2 = x2[n / 2];
    for(int i = 0; i < n; i++){
        cout << (xs[i] <= n1 ? n2 : n1) << '\n';
    }
}

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
#include<random>
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
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde) FUNC(printdu);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ return in >> p.first >> p.second; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }

ll ps[60];

ll eat(ll n, ll num, ll x){
    printde(n, num, x);
    if(x <= 0){ return 0; }
    if(n == 0){ return (bool)x; }
    if(x * 2 - 1 == num){
        return ps[n - 1] + 1;
    }else if(x * 2 - 1 > num){
        ll mid = num / 2 + 1;
        return ps[n - 1] + eat(n - 1, num / 2 - 1, x - mid) + 1;
    }else{
        return eat(n - 1, num / 2 - 1, x - 1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;
    ll num = 1;
    ps[0] = 1;
    for(int i = 0; i < n; i++){
        ps[i + 1] = ps[i] * 2 + 1;
        num = num * 2 + 3;
    }
    cout << eat(n, num, x) << '\n';
}

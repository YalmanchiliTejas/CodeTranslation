#include<algorithm>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<random>
#include<set>
#include<sstream>
#include<sys/time.h>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde) FUNC(printdu);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ return in >> p.first >> p.second; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }

vector<int> as;
ll memo[3001][3001];
ll calcMaxi(int i, int j){
    if(i == j){ return as[i]; }
    if(memo[i][j]){ return memo[i][j]; }
    ll c1 = as[i], c2 = as[j];
    c1 -= calcMaxi(i + 1, j);
    c2 -= calcMaxi(i, j - 1);
    return memo[i][j] = max(c1, c2);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    as.resize(n); cin >> as;
    cout << calcMaxi(0, n - 1) << '\n';
}

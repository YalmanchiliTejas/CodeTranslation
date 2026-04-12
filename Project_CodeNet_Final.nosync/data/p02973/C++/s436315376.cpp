//{{{
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
FUNC(prints) FUNC(printw) FUNC(printwe) FUNC(printb) FUNC(printbe) FUNC(printd) FUNC(printde) FUNC(printdu);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ return in >> p.first >> p.second; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }
//}}}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> as(n); cin >> as;
    set<pair<int, int>> nums;
    int ans = 0;
    for(size_t i = 0; i < as.size(); i++){
        auto a = as[i];
        auto ite = nums.lower_bound(pair<int, int>(a, -1));
        if(ite == nums.begin()){
            ans++;
        }else{
            ite--;
            nums.erase(ite);
        }
        nums.emplace(a, i);
        // auto ite = lower_bound(nums.begin(), nums.end(), pair<int, int>(a, -1));
    }
    cout << ans << '\n';
}

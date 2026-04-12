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
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <ostream& out = cout, class... T> void prints(T&&...){ }
template <ostream& out = cout, class... T> void printd(T&&...){ }
template <ostream& out = cout, class... T> void printde(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

int main(){
    int n; cin >> n;
    vector<ll> as(n);
    for(int i = 0; i < n; i++){
        cin >> as[i];
    }
    ll ans = 0;
    while(1){
        sort(as.rbegin(), as.rend());
        // if(as[0] < n && as.back() >= 0){ break; }
        if(as[0] < n){ break; }
        ll num = as[0] / n;
        as[0] -= num * n;
        for(int i = 1; i < n; i++){
            as[i] += num;
        }
        ans += num;
    }
    cout << ans << '\n';
    return 0;
}

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
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

int main(){
    int n; cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(i & 1){
            dq.push_front(a);
        }else{
            dq.push_back(a);
        }
    }
    vector<int> ans(dq.begin(), dq.end());
    if(n & 1){
        reverse(ans.begin(), ans.end());
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}

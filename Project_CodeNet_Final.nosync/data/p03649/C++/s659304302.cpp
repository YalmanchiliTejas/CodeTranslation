#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const int INF = 1001001001;
const int mod = 1e+9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    // bool flag = true;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        // if(a[i] >= n)   flag = false;
    }
    // if(flag){
    //     cout << 0 << endl;
    //     return 0;
    // }

    ll sum = accumulate(a.begin(), a.end(), 0ll);
    int limit = n * (n - 1);
    auto C = [](ll num, ll judge, vector<ll>& v){
        ll res = 0;
        int sz = v.size();
        for(int i = 0; i < sz; ++i){
            res += max(0ll, (v[i] - num) / (sz + 1));
        }
        return (res <= judge) && (res >= judge - sz);
    };
    
    ll res = 0;
    ll x = max(sum - limit, 0ll);
    if(sum > limit){
        for(int i = 0; i < n; ++i){
            a[i] += x;
        }
        ll lb = 0, ub = 1e+16 + 1001;
        while(ub - lb > 1){
            ll mid = (lb + ub) / 2;
            bool bs = C(mid, x, a);
            if(bs)  lb = mid;
            else    ub = mid;
        }
        for(int i = 0; i < n; ++i){
            ll cnt = max(0ll, (a[i] - lb) / (n + 1));
            res += cnt;
            a[i] -= cnt * (n + 1);
        }
    }
    
    auto processed = [](vector<ll>& v){
        int sz = v.size();
        for(int i = 0; i < sz; ++i){
            if(v[i] >= sz)  return false;
        }
        return true;
    };
    while(!processed(a)){
        sort(a.begin(), a.end(), greater<ll>());
        if(res >= x){
            a[0] -= n;
            for(int i = 1; i < n; ++i){
                a[i] += 1;
            }
            ++res;
        }
        else{
            a[0] -= n + 1;
            ++res;
        }
    }

    cout << res << endl;
}
#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    ll x; cin>>x;
    vector<ll> len(n+1, 1), lp(n+1, 0);
    for(int i=0; i<n; i++){
        len[i+1] = len[i] * 2 + 3;
        lp[i+1] = lp[i] * 2 + 1;
    }

    ll ans = 0;
    ll lb = 1, ub = len[n];
    for(int i=0; i<n; i++){
        ll mid = (lb + ub) / 2;
        int level = n - i;

        if(lb == x) break;
        if(ub == x){
            ans += lp[level] * 2 + 1;
            break;
        }
        
        if(mid < x){
            lb = mid + 1;
            ub--;
            ans += lp[level] + 1;
        }
        else if(x < mid){
            ub = mid - 1;
            lb++;
        }
        else{
            ans += lp[level] + 1;
            break;
        }

        if(i == n - 1) ans++;
    }

    cout << ans << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
ll mod = 1000000007;

int main(){
    ios::sync_with_stdio(false);

    ll n, x, m;
    cin >> n >> x >> m;
    vector<pair<ll,ll>> c(100005);
    vector<int> A(100005);
    ll a = x;

    ll k = 0;
    while(k < 100005){
        if(c[a].first) break;
        c[a].first++;
        c[a].second = k; //何番目か
        A[k] = a;
        a = a * a % m;
        k++;
    }


    ll ans = 0,temp = 0;
    if(n <= k) {
        rep(i,n) ans += A[i];
        cout << ans << endl;
        return 0;
    }

    for(int i = 0; i < c[a].second; ++i) ans += A[i];
    for(int i = c[a].second; i < k; ++i) temp += A[i];

    temp *= ((n-c[a].second) / (k-c[a].second));
    for(int i = c[a].second; i < c[a].second - 1 + (n-c[a].second+1) % (k-c[a].second); ++i) ans += A[i];

    cout << ans + temp << endl;

}
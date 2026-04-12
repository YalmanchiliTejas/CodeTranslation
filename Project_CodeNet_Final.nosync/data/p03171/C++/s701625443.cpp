#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
typedef long long int ll;

#define PI (acos(-1))
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define dumparr(x) cerr << #x ; for(auto elem: x){cerr << " " << elem;} cerr << endl;
#define dumppairs(x) cerr << #x ; for(auto elem: x){cerr << "(" << elem.first << " " << elem.second << ") ";} cerr << endl;
#define dumpline cerr << "**********************" << endl;
#define dumpwline(x) cerr << "******** " << #x << "=" << (x) << " ********" << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))



vector <vector <ll>> dp(3000+1, vector<ll>(3000+1, 1e18));
vector <ll> as;

ll calc(ll begin, ll end, bool taro_turn){
    if (begin == end){
        return 0;
    }
    if (dp[begin][end] != 1e18){
        return dp[begin][end];
    }
    ll a = calc(begin+1, end, !taro_turn);
    ll b = calc(begin, end-1, !taro_turn);
    if (taro_turn){
        a += as[begin];
        b += as[end-1];
    } else {
        a -= as[begin];
        b -= as[end-1];
    }
    ll ret;
    if (taro_turn){
        ret = max(a, b);
    } else {
        ret = min(a, b);
    }
    dp[begin][end] = ret;
    return ret;
}


int main(void){
    ll n; cin >> n;
    REP(i, n){
        ll a; cin >> a;
        as.push_back(a);
    }
    cout << calc(0, n, true) << endl;
    return 0;
}
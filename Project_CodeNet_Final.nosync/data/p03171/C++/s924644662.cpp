#include <bits/stdc++.h>                 // [PRIMES]               1777 ~2^10.80
using namespace std;                     //                       10333 ~2^13.33
using ll = long long;                    // seq 1 128 | factor   100333 ~2^16.61
using vl = vector<ll>;                   //   | grep -v ' .* '  1300111 ~2^20.31
using vvl = vector<vl>;                  //                    10300777 ~2^23.30
using pll = pair<ll,ll>;                 //                   100400999 ~2^26.58
using vb = vector<bool>;                 //                  1300400999 ~2^30.28
const ll oo = 0x3f3f3f3f3f3f3f3fLL;      //                 10200500333 ~2^33.25
const double eps = 1e-9;                 //                100200400777 ~2^36.54
#define sz(c) ll((c).size())             //               1200300700111 ~2^40.13
#define all(c) begin(c),end(c)           //              10200300500777 ~2^43.21
#define mp make_pair                     //             100200300400777 ~2^46.51
#define mt make_tuple                    //            1200300400600999 ~2^50.09
#define pb push_back                     //           10200300400600111 ~2^53.18
#define eb emplace_back                  //          100200300400600333 ~2^56.48
#define xx first                         //         1200300400500800999 ~2^60.06
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
#define FORD(i,a,b) for (ll i=ll(b)-1; i>=(a); i--)
#define TR(X) ({if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })
    
ll n;
vl numbs;
vector<vvl> dp; //start, end, max = 1, min = 0

ll try_winning(bool max_turn, ll start, ll end){
    if(start == end){
        return 0;
    }
    if(max_turn && dp[start][end-1][1] != LLONG_MAX) return dp[start][end-1][1];
    if(!max_turn && dp[start][end-1][0] != LLONG_MAX) return dp[start][end-1][0];

    ll take_start = try_winning(!max_turn, start+1, end);
    ll take_end = try_winning(!max_turn, start, end-1);

    if(max_turn){
        dp[start][end-1][1] =  max(take_start+numbs[start], take_end+numbs[end-1]);
        return  dp[start][end-1][1];  
    }else {
        dp[start][end-1][0] = min(take_start-numbs[start], take_end-numbs[end-1]);
        return dp[start][end-1][0];
    }
}

int main() {

    cin >> n;
    numbs.resize(n);
    dp.assign(n, vvl(n, vl(2, LLONG_MAX)));
    FOR(i, 0, n){
        cin >> numbs[i];
    }
    cout << try_winning(true, 0, n) << endl;

    return 0;
}


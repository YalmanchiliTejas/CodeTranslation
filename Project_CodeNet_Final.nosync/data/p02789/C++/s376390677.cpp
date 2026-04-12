#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> P;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)

/***** define constant start *******/
const ll MOD = 1000000007;
const double PI = 3.1415926535897932;
const ll INF = 10000000000;
/****** define constant end ********/


/****** define variable start ******/
ll n, m;
/******* define variable end *******/

ll solve(){
    cin >> n >> m;
    if(n == m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
int main(){
    //clock_t start = clock();
    cout << std::fixed << std::setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll end_solve = solve();
    /*
    clock_t end = clock();
    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("time %lf[ms]\n", time);
    */
    return (int)end_solve;
}

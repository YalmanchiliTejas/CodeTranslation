#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a(n);rep(i,n){cin>>a.at(i);}
    vector<vector<ll> > dp(n,vector<ll>(n,-1));
    function<ll(int,int)> solve = [&](int from, int to){
        assert(0<=from&&from<=to&&to<=n-1);
        if(dp[from][to]!=-1){return dp[from][to];}
        if(to-from<=1){
            return max(a.at(from), a.at(to));
        }
        ll res = max(a.at(from)+min(solve(from+2,to),solve(from+1,to-1)),
        a.at(to)+min(solve(from+1,to-1),solve(from,to-2)));
        return dp[from][to] = res;

    };
    ll sum_a = solve(0,n-1);
    ll sum_b=0;
    rep(i,n){
        sum_b += a.at(i);
    }
    sum_b -= sum_a;
    ll res = sum_a-sum_b;
    cout << res << endl;
    return 0;
}

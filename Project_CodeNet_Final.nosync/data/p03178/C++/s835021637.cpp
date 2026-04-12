#include<bits/stdc++.h>
using namespace std;
using Int = long long;
string s; Int D;
constexpr Int mod = 1e9 + 7;
Int solve(Int idx, Int cmod, bool bind,
vector<vector<vector<Int>>>&dp,vector<vector<vector<bool>>>&visit){
       Int res = 0;
       if(idx + 1 == s.size()){
           Int ub = ( not bind ? 9 : s[idx] - '0');
           for(Int i = 0; i <= ub; ++i)
               res += (i % D == cmod);
           return res;
       }
       if(visit[idx][cmod][bind])
           return dp[idx][cmod][bind];
       Int num = (not bind ? 9 : s[idx] - '0' );
       for(Int i = 0; i <= num; ++i){
           res += solve(idx + 1,(D + cmod - i % D)%D,bind and num == i,dp,visit);
           res %= mod;
       }
       visit[idx][cmod][bind] = true;
       return dp[idx][cmod][bind] = res;
   };
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
int main(){
    cin >> s;
    cin >> D;
    auto dp    = vectors(s.size(),D,2, 0LL);
    auto visit = vectors(s.size(),D,2,false);
    cout << (mod + solve(0LL,0LL,true,dp,visit)-1 ) % mod << endl;
}


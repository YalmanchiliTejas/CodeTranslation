#include <bits/stdc++.h>
#define ALL(v) (v).begin(), (v).end()
#define INF 1e9
#define pb push_back
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using numr=std::numeric_limits<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define MOD 1000000007
#define MOD2 998244353

ll f(const vector<pll>& L, ll length, ll level){
   if(level == 0){
       //assert(1 <= length);
       return 1;
   } 
   ll res = 0;

   if(length == 1){
       return 0;
   }
   --length;

   if(length <= L[level-1].first){
       return f(L, length, level-1);
   }
   length -= L[level - 1].first;
   res += L[level - 1].second;

   if(length == 1){
       return res + 1;
   }
   --length;
   ++res;

   if(length <= L[level - 1].first){
       return res + f(L, length, level-1);
   }   
   length -= L[level - 1].first;
   res += L[level - 1].second;

   //assert(length <= 1);
   return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, X;
    cin >> N >> X;
    vector<pair<ll, ll>> L(N + 1);
    L[0] = {1, 1};
    for(ll i = 1; i<L.size();i++){
        L[i].first = L[i-1].first * 2 + 3;
        L[i].second = L[i-1].second * 2 + 1;
    }
    cout << f(L, X ,N) << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll H,W;
char field[10][10];

void dfs(ll y,ll x){
   field[y][x] = 'O';
   if(field[y+1][x] == '#') dfs(y+1,x);
   if(field[y][x+1] == '#') dfs(y,x+1);
}

int main(){
   cin >> H >> W;
   ll cnt = 0;
   rep(i,H) rep(j,W){
      cin >> field[i][j];
      if(field[i][j] == '#')cnt++;
   }
   if(cnt != H + W - 1){
      cout << "Impossible" << endl;
   }else{
      dfs(0,0);
      if(field[H-1][W-1] == 'O'){
         cout << "Possible" << endl;
      }else{
         cout << "Impossible" << endl;
      }
   }
}

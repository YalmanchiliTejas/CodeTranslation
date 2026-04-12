#include <bits/stdc++.h>
#define INF 100100100
#define MOD 1000000007

using namespace std;
using ll = long long;
using ull = unsigned long long ;

#define FOR(i,n) for(ll i=0;i<n;i++)

vector<vector<int> >edge;
int ans = 0;
int N;

void func(int memo,int now){
   if(__builtin_popcount(memo) == N){
      ans++;
      return ;
   }
   for(int i=0;i<edge[now].size();i++){
      if((memo>>(edge[now][i]-1))&1)continue;
      func(memo|(1<<(edge[now][i]-1)),edge[now][i]);
   }
   return ;
}

int main(int argc, char const* argv[]){
   ios::sync_with_stdio(false);
   cin.tie(0); 
   int M;
   cin >> N >> M;
   edge.resize(N+1);
   FOR(i,M){
      int a;
      int b;
      cin >> a >> b;
      edge[a].push_back(b);
      edge[b].push_back(a);
   }
   func(1,1);
   cout << ans << endl;
   return 0;
}

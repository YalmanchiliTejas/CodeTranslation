#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int dfs(int v, int n, bool g[8][8], bool seen[8]){
   int ans =0;
   bool all = true;
   rep(i, n){ 
      if(seen[i] == false)
         all = false;
   }

   if(all){
      //全て辿れた
      return 1;
   }

   for(int i=0;i<n;++i){
      if(g[v][i]==false) continue;
      if(seen[i]) continue;

      seen[i]=true;
      ans +=dfs(i,n,g,seen);
      seen[i]=false;
   }
  
   return ans;
}

int main()
{    
   int n ,m;
   cin >> n >> m;

   bool g[8][8];
   rep(i,8)rep(j,8) g[i][j] = false;
   rep(i,m){
      int a , b;
      cin >> a >> b;
      --a;
      --b;

      g[a][b] = true;
      g[b][a] = true;
   }

   bool seen [8];
   rep(i,n) seen[i] = false;
   seen[0] = true;
   cout << dfs(0, n, g,seen)<< endl;
}
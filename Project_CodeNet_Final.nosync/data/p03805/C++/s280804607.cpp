#include <bits/stdc++.h> 

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

#define INF (1<<(4*4-1))
#define MOD 1000000007

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);

   int N,M;
   cin>>N>>M;
   vector<vector<bool> >e(N,vector<bool>(N,false));
   for(int i=0;i<M;i++){
      int x,y;
      cin>>x>>y;
      x--,y--;
      e[x][y]=true;
      e[y][x]=true;
   }

   vector<int>node(N);
   for(int i=0;i<N;i++)node[i]=i;

   ll ans = 0;
   do{
      if(node[0]!=0)continue;
      bool flg=true;
      for(int i=0;i<N-1;i++){
         if(!e[node[i]][node[i+1]])flg=false;
      }
      if(flg)ans++;
   } while(next_permutation(node.begin(),node.end()));
   cout<<ans<<endl;
   return 0;
}

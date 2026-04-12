#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

   int N, M;
   cin>> N>> M;
   int g[10][10];
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         g[i][j]=0;
      }
   }
   for(int i=0; i<M; i++){
      int a, b;
      cin>> a>> b;
      a--; b--;
//      g[a].push_back(b);
//      g[b].push_back(a);
      g[a][b]=g[b][a]=1;
   }

   vector<int> _v;
   int r=0;
   for(int i=1; i<N; i++) _v.push_back(i);
   do{
      bool ok=true;
      int p=0;
      for(int j: _v){
         ok&=g[p][j];
         p=j;
      }
      if(ok) r++;
   }while(next_permutation(_v.begin(), _v.end()));

   cout<< r<< endl;

   return 0;
}

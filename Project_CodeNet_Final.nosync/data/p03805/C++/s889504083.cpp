#include<iostream>
#include<vector>

using namespace std;
int N, M;
vector<int> g[10];
int used[10];

int rec(int i){

   int k=0;
   for(int i=0; i<N; i++) k+=used[i];
   if(k==N) return 1;

   int ret=0;
   for(int j: g[i]){
      if(used[j]) continue;
      used[j]=1;
      ret+=rec(j);
      used[j]=0;
   }

   return ret;
}

int main(){

   cin>> N>> M;
   for(int i=0; i<M; i++){
      int a, b;
      cin>> a>> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
   }

   used[0]=1;
   cout<< rec(0)<< endl;

   return 0;
}

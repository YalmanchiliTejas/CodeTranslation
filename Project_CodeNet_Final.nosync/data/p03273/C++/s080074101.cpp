#include <bits/stdc++.h>

#define INF INT_MAX/2
#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long ;

int main(){
   std::ios::sync_with_stdio(false);
   std::cin.tie(0);

   int H,W;
   cin>>H>>W;
   vector<string>A(H);
   for(int i=0;i<H;i++)cin>>A[i];
   vector<bool>tate(H,true),yoko(W,true);
   for(int i=0;i<H;i++){
      bool flg = true;
      for(int j=0;j<W;j++){
         if(A[i][j] == '#')flg = false;
      }
      if(flg)tate[i]=false;
   }
   for(int j=0;j<W;j++){
      bool flg = true;
      for(int i=0;i<H;i++){
         if(A[i][j] == '#')flg = false;
      }
      if(flg)yoko[j] = false;
   }

   for(int i=0;i<H;i++){
      if(tate[i]){
         for(int j=0;j<W;j++){
            if(yoko[j])cout<<A[i][j];
         }
         cout<<endl;
      }
   }
   return 0;
}

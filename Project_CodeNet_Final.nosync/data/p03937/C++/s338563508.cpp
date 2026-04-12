#include<bits/stdc++.h>
using namespace std;

int main(void){
   int H,W;
   cin>>H>>W;
   vector<vector<char>> A(H,vector<char>(W));
   for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
         cin>>A[i][j];
      }
   }
   int h_max=0;
   for(int i=0;i<W;i++){
      if(A[0][i]=='#') h_max=max(h_max,i);
   }
   bool flag=true;
   for(int i=1;i<H;i++){
      int judge=W+1;
      for(int j=0;j<W;j++){
         if(A[i][j]=='#'){
            judge=min(judge,j);
         }
      }
      if(judge<h_max){
         flag=false;
         break;
      }
      for(int j=0;j<W;j++){
         if(A[i][j]=='#'){
            h_max=max(h_max,j);
         }
      }
   }
   if(flag) cout<<"Possible"<<endl;
   else cout<<"Impossible"<<endl;
   return 0;
}

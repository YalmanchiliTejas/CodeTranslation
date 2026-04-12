#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
int main() {
 int H,W;
 cin>>H>>W;
 vector<vector<char>> a(H,vector<char>(W));
 for(int i=0;i<H;i++){
     for(int j=0;j<W;j++){
         cin>>a[i][j];
     }
 }
vector<bool>tate(W,false);
vector<bool>yoko(H,false);

 for(int i=0;i<H;i++){
     for(int j=0;j<W;j++){
         if(a[i][j]=='#'){yoko[i]=true;break;}
     }
 }
  for(int i=0;i<W;i++){
     for(int j=0;j<H;j++){
         if(a[j][i]=='#'){tate[i]=true;break;}
     }
  }
  for(int i=0;i<H;i++){
     for(int j=0;j<W;j++){
        if(yoko[i]&&tate[j]){cout<<a[i][j];}
     } 
    if(yoko[i]){cout<<endl;}
  }
 return 0;}
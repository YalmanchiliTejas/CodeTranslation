#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int H,W;
  cin >> H >> W;
  vector<string> S(110),T(110);
  for(int i=0;i<H;i++)cin >> S[i];
  for(int i=0;i<H;i++)T[i]="";
  for(int i=0;i<W;i++){
    bool q=false;
    for(int j=0;j<H;j++){if(S[j][i]=='#')q=true;}
    if(q){for(int j=0;j<H;j++)T[j]+=S[j][i];}
  }
  for(int i=0;i<H;i++){
    bool w=false;
    for(int j=0;j<T[i].size();j++){if(T[i][j]=='#')w=true;}
    if(w){cout << T[i] << endl;}
  }
}
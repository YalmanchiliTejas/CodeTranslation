#include <bits/stdc++.h>
using namespace std;
int main(){
 int H,W;
  cin>>H>>W;
  vector<vector<char>>in(H,vector<char>(W));
  for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
      cin>>in[i][j];
    }
  }
  vector<vector<char>>out(H,vector<char>(W,'o'));
  vector<int>m(H);
  //空白行のマーク
  for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
      if(in[i][j]=='#') {
        m[i]=1;
        break;
      }
      if(j==W-1){
        for(int k=0;k<W;k++){
          out[i][k]='x';
        }
      }
    }
  }
  //空白列のマーク
  for(int j=0;j<W;j++){
	for(int i=0;i<H;i++){
      if(in[i][j]=='#') break;
      if(i==H-1){
        for(int k=0;k<H;k++){
          out[k][j]='x';
        }
      }
    }
  }
  
  for(int i=0;i<H;i++){
	for(int j=0;j<W;j++) {
      if(out[i][j]=='o') cout<<in[i][j];
      if(j==W-1&&m[i]==1) cout<<endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin>>H>>W;
  vector<string> grid(H);
  for(int i=0;i<H;i++){
    string line;
    cin>>line;
    grid[i]=line;
  }
  string white(W,'.');
  vector<int> row(H),column(W);

  for(int i=0;i<H;i++){
    if(grid[i]!=white){
      row[i]=1;
    }
  }

  for(int i=0;i<W;i++){
    for(int j=0;j<H;j++){
      if(grid[j][i]=='#'){
        column[i]=1;
      }
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(row[i]==1 && column[j]==1){
        cout<<grid[i][j];
      }
    }
    if(row[i]==1){
      cout<<endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>> A(H,vector<char>(W));
  for (int i=0;i<H;i++) {
    for (int j=0;j<W;j++) {
      cin>>A.at(i).at(j);
    }
  }
  for (int i=0;i<H;i++) {
    for (int j=0;j<W;j++) {
      if(A.at(i).at(j)=='#')
        break;
      if(j==W-1) {
        for (int k=0;k<W;k++)
          A.at(i).at(k)='0';
      }
    }
  }
  for(int j=0;j<W;j++) {
    for (int i=0;i<H;i++) {
      if(A.at(i).at(j)=='#')
        break;
      if(i==H-1) {
        for (int k=0;k<H;k++)
          A.at(k).at(j)='0';
      }
    }
  }
  for (int i=0;i<H;i++) {
    bool b=true;
    for (int j=0;j<W;j++) {
      if(A.at(i).at(j)!='0') {
        cout<<A.at(i).at(j);
        b=false;
      }
      if((j==W-1)&&(b==false))
        cout<<endl;
    }
  }
}

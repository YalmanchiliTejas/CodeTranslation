#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  int h=H; 
  vector<vector<char>> a(H, vector<char>(W));
  for(int i=0;i<H;i++) {
      for(int j=0;j<W;j++) {
          cin >> a.at(i).at(j);
      }
  }

  vector<bool> counti(H,false);
  vector<bool> countj(W,false);

  for(int i=0;i<H;i++) {
      for(int j=0;j<W;j++) {
          if(a.at(i).at(j)=='#') counti.at(i)=true;
      }
  }

  for(int j=0;j<W;j++) {
      for(int i=0;i<H;i++) {
          if(a.at(i).at(j)=='#') countj.at(j)=true;
      }
  }

  for(int i=0;i<H;i++) {
      for(int j=0;j<W;j++) {
          if(counti.at(i)&&countj.at(j)) cout << a.at(i).at(j);
      }
      if(counti.at(i)) cout << endl;
  }

  /*for(int i=0;i<H;i++) {
      int count=0;
      for(int j=0;j<W;j++) {
          if(a.at(i).at(j)=='#') count++;
      }

      if(count==0) {
          for(int j=0;j<W;j++) {
              if(H==1) {
                  break;
              }
              for(int k=i;k<H-1;k++){
                  a.at(k).at(j)=a.at(k+1).at(j);
              }
          }
          i--;
          H--;
      }
  }

  for(int i=0;i<W;i++) {
      int count=0;
      for(int j=0;j<H;j++) {
          if(a.at(j).at(i)=='#') count++;
      }
      if(count==0) {
          for(int j=0;j<H;j++) {
              a.at(j).at(i)=a.at(j).at(i+1);
          }
          i--;
          W--;
      }
  }

  cout << H << " " << W << endl;

  for(int i=0;i<H;i++) {
      for(int j=0;j<W;j++) {
          cout << a.at(i).at(j);
      }
      cout << endl;
  }*/
}
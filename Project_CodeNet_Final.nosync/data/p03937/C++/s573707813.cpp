#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int h,w;
  cin >> h >> w;

  vector<vector<char>> grid(h+1,vector<char>(w));
  rep(i,h)rep(j,w) cin >> grid.at(i).at(j);

  rep(i,h) grid.at(i).push_back('.');
  rep(i,w) grid.at(h).at(i) = '.';

  int nowx=0, nowy=0;
  int pass=0;
  bool check1=false;
  while(1){
    //cout << nowx << " " << nowy << endl;
    if(nowx==h-1&&nowy==w-1){check1=true; pass++; break;}

    if(grid.at(nowx).at(nowy+1)=='#'&&grid.at(nowx+1).at(nowy)=='#') break;
    else if(grid.at(nowx).at(nowy+1)=='#'){nowy=nowy+1; pass++; continue;}
    else if(grid.at(nowx+1).at(nowy)=='#'){nowx=nowx+1; pass++; continue;}
    
    break;
  }

  bool check2=false;
  int count=0;
  rep(i,h)rep(j,w){
    if(grid.at(i).at(j)=='#') count++;
  }
  if(pass==count) check2=true;
  //cout << pass << " " << count;

  if(check1&&check2) cout << "Possible";
  else cout << "Impossible";
  
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> tbl(h,vector<char>(w));
  vector<int> cf(w,0);
  vector<int> rf(h,0);
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin >> tbl.at(i).at(j);
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(tbl.at(i).at(j)=='#')
        rf.at(i) = cf.at(j) = 1;
  for(int i=0;i<h;i++)
    if(rf.at(i)==1){
      for(int j=0;j<w;j++)
        if(cf.at(j)==1)
          cout << tbl.at(i).at(j);
      cout << endl;
    }
}

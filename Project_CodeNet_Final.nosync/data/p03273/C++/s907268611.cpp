#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> tbl(h,vector<char>(w));
  vector<int> rf(h,1);
  vector<int> cf(w,1);
  char tmp;
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin >> tbl.at(i).at(j);
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(tbl.at(i).at(j)!='.')
        rf.at(i) = 0;
  for(int i=0;i<w;i++)
    for(int j=0;j<h;j++)
      if(tbl.at(j).at(i)!='.')
        cf.at(i) = 0;

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(cf.at(j)==0&&rf.at(i)==0){
        cout << tbl.at(i).at(j);
      }
    }
    if(rf.at(i)==0)
      cout << endl;
  }
}

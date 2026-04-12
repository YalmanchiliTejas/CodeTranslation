#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>>m(0,vector<char>(W));
  for(int i=0;i<H;i++){
    int k=0;
    vector<char>a(W);
    for(int j=0;j<W;j++){
      cin >> a.at(j);
      if(a.at(j)=='.')
        k++;
    }
    if(k!=W){
      m.push_back(a);
    }//##.# ##.# .#.#
  }
  vector<vector<char>>mm(0,vector<char>(m.size()));//0,3
  for(int i=0;i<W;i++){
    int k=0;
    vector<char>a(m.size());
    for(int j=0;j<m.size();j++){
      a.at(j)=m.at(j).at(i);
      if(a.at(j)=='.')
        k++;
    }
    if(k!=m.size()){
      mm.push_back(a);
    }
  }
  vector<vector<char>>e(mm.at(0).size(),vector<char>(mm.size()));
  for(int i=0;i<mm.at(0).size();i++){
    for(int j=0;j<mm.size();j++){
      e.at(i).at(j)=mm.at(j).at(i);
    }
  }
  for(int i=0;i<e.size();i++){
    for(int j=0;j<e.at(0).size();j++){
      cout << e.at(i).at(j);
    }
    cout << endl;
  }
}
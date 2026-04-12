#include<iostream>
#include<vector>
using namespace std;

int main(){
  int h,w; cin >> h >> w;
  vector<vector<char>> cell(h,vector<char>(w));
  vector<int> row;
  vector<int> column;
  
  for(int i=0;i<h;i++){
    int flag=0;
    for(int j=0;j<w;j++){
      char c; cin >> c;
      cell.at(i).at(j)=c;
      if(c=='#')flag=1;
    }
    if(flag) row.push_back(i);
  }

  for(int j=0;j<w;j++){
    int flag=0;
    for(int i=0;i<h;i++){
      char c=cell.at(i).at(j);
      if(c=='#')flag=1;
    }
    if(flag) column.push_back(j);
  }

  for(int i: row){
    for(int j: column){
      cout << cell.at(i).at(j);
    }
    cout << endl;
  }
  
}

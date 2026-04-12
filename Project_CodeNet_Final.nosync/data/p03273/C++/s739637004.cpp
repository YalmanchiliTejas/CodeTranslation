#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> e2(int a, int j, vector<vector<char>> c){
  for(int i=0;i<a;i++)c.at(i).erase(c.at(i).begin()+j);
  return c;
}


int main() {
  int a,b;
  cin>>a>>b;
  vector<vector<char>> c(a,vector<char>(b));
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      cin>>c.at(i).at(j);
    }
  }
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      if(c.at(i).at(j)=='#')break;
      else if(j==b-1){
        c.erase(c.begin()+i);
        a-=1;
        i-=1;
      }
    }
  }
  for(int j=0;j<b;j++){
    for(int i=0;i<a;i++){
      if(c.at(i).at(j)=='#')break;
      else if(i==a-1){
        c=e2(a,j,c);
        b-=1;
        j-=1;
      }
    }
  }
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
    cout << c.at(i).at(j);
    }
    cout << endl;
  }
}
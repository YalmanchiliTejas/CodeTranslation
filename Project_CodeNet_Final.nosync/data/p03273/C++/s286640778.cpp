#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      cin >> a.at(i).at(j);
  }
  
  for(int i=0;i<h;i++){
    int k=0;
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)=='#')
        k++;
    }
    if(k==0){
      for(int j=0;j<w;j++)
        a.at(i).at(j)=' ';
    }
  }
  
  for(int i=0;i<w;i++){
    int k=0;
    for(int j=0;j<h;j++){
      if(a.at(j).at(i)=='#')
        k++;
    }
    if(k==0){
      for(int j=0;j<h;j++)
        a.at(j).at(i)=' ';
    }
  }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)!=' ')
        cout << a.at(i).at(j);
    }
    int k=0;
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)==' ')
        k++;
    }
    if(k!=w)
      cout << endl;
  }
}
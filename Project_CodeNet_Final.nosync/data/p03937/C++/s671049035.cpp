#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> vec(h,vector<char>(w));
  int a = 0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
    cin >> vec.at(i).at(j);
    }
  }
  for(int i=0;i<h+w-1;i++){
    int k=0;
    for(int j=max(0,i-w+1);j<=min(i,h-1);j++){
      if(vec.at(j).at(i-j)=='#'){
        k++;
      }
      if(k==2){
        a = 1;
        break;
      }
    }
  }
  if(a==0)
        cout << "Possible" << endl;
  else
        cout << "Impossible" << endl;
}
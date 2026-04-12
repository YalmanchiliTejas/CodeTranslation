#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for (int i=0 ; i<h ; i++){
    for (int j=0 ; j<w ; j++)
      cin >> a.at(i).at(j);
  }
  
  for (int i=0 ; i<h ; i++){
    int white = 0;
    for (int j=0 ; j<w ; j++){
      if (a.at(i).at(j) == '.')
        white++;
      else
        break;
    }
    if (white == w){
      a.erase(a.begin() + i);
      h--;
      i--;
    }
  }
  
  for (int i=0 ; i<w ; i++){
    int white = 0;
    for (int j=0 ; j<h ; j++){
      if (a.at(j).at(i) == '.')
        white++;
      else
        break;
    }
    if (white == h){
      for (int j=0 ; j<h ; j++)
        a.at(j).erase(a.at(j).begin() + i);
      w--;
      i--;
    }
  }
  
  w = a.at(0).size();
  
  for (int i=0 ; i<h ; i++){
    for (int j=0 ; j<w ; j++)
      cout << a.at(i).at(j);
    cout << endl;
  }
}
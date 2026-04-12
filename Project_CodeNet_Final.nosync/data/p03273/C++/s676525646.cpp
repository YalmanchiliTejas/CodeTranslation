#include<iostream>
#include<vector>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  for(int i=0;i<h;i++){
    int cnt=0;
    for(int j=0;j<w;j++){
      cin >> a[i][j];
      if(a[i][j]=='.') cnt++;
    }
    if(cnt==w){
      i--;
      h--;
    }
  }
  for(int j=0;j<w;j++){
    int cnt=0;
    for(int i=0;i<h;i++){
      if(a[i][j]=='.') cnt++;
    }
    if(cnt==h){
      for(int i=0;i<h;i++){
	a[i].erase(a[i].begin()+j);
      }
      j--;
      w--;
    }
  }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout << a[i][j];
    }
    cout << "\n";
  }


  
  return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> grid(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> grid.at(i).at(j);
    }
  }
  
  /*
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout << grid.at(i).at(j);
    }
    cout << "" << endl;
  }
  */
  vector<int> hcheck(h,0);
  vector<int> wcheck(w,0);
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(grid.at(i).at(j) == '#'){
        hcheck.at(i) = 1;
        wcheck.at(j) = 1;
      }
    }
  }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(hcheck.at(i) == 1 && wcheck.at(j) == 1){
        cout << grid.at(i).at(j);
      }
    }
    if(hcheck.at(i) == 1){
	  cout << endl;
    }
  }
  
  return(0);
}
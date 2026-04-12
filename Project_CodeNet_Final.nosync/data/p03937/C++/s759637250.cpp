#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int h,w;
  cin >> h >> w;
  
  vector<vector<char>>mass(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> mass[i][j];
    }
  }
  
  bool can = true;
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(mass[i][j] == '#'){
        for(int k=i + 1;k<h;k++){
          for(int l=0;l<j;l++){
            if(mass[k][l] == '#'){
              can = false;
            }
          }
        }
      }
    }
  }
  
  if(can)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  
  return 0;
}

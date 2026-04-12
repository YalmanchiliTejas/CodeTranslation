#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  char a[100][100];
  int h, w;
  cin >> h >> w;

  bool tumeru = false;
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < h; ++i){
    tumeru = true;
    for(int j = 0; j < w; ++j){
      if(a[i][j] != '.'){
        tumeru = false;
        break;
      }
    }
    if(tumeru == true){
      --h;
      for(int k = i; k < h; ++k){
        for(int l = 0; l < w; ++l){
          a[k][l] = a[k + 1][l];
        }
      }
      --i;
    }

  }

  for(int i = 0; i < w; ++i){
    tumeru = true;
    for(int j = 0; j < h; ++j){
      if(a[j][i] != '.'){
        tumeru = false;
        break;
      }
    }
    if(tumeru == true){
      --w;
      for(int k = i; k < w; ++k){
        for(int l = 0; l < h; ++l){
          a[l][k] = a[l][k+1];
        }
      }
      i--;
    }

  }

  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      cout << a[i][j];
    }
    cout << endl;
  }



}

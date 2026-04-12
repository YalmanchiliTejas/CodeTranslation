#include<iostream>
#define MAX 105
using namespace std;

int main(){
  int h, w;
  char a[MAX][MAX];
  cin >> h >> w;
  bool hb[h], wb[w];
  for(int i = 0; i < w; i++) wb[i] = false;
  for(int i = 0; i < h; i++){
    hb[i] = false;
    for(int j = 0; j < w; j++){
      cin >> a[i][j];
      if(a[i][j] == '#'){
        hb[i] = true;
        wb[j] = true;
      }
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(hb[i] && wb[j]){
        cout << a[i][j];
      }
    }
    if(hb[i]){
      cout << endl;
    }
  }
}


#include <bits/stdc++.h>
using namespace std;

int max_n=100;
int main(){
  int h,w;
  std::cin >> h>>w;
  char a[max_n][max_n];
  bool han[max_n][max_n];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      /* code */
      han[i][j]=true;
    }
    /* code */
  }
  for (int i = 0; i < h; i++) {
    /* code */
    for (int j = 0; j < w; j++) {
      /* code */
      std::cin >> a[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    /* code */
    bool hoge=false;
    for (int j = 0; j < w; j++) {
      /* code */
      if(a[i][j]=='#')hoge=true;
    }
    if(not hoge){
      for (int j = 0; j < w; j++) {
        /* code */
        han[i][j]=false;
      }
    }
    
  }
  
  for (int i = 0; i < w; i++) {
    /* code */
    bool hoge=false;
    for (int j = 0; j < h; j++) {
      /* code */
      if(a[j][i]=='#')hoge=true;
    }
    if(not hoge){
      for (int j = 0; j < h; j++) {
        /* code */
        han[j][i]=false;
      }
    }
    
  }
  for (int i = 0; i < h; i++) {
    int j;
    bool hoge=false;
    for ( j = 0; j < w; j++) {
      /* code */
      if(han[i][j]){
        std::cout <<a[i][j];
        hoge=true;
      }
    }
    /* code */
    if(hoge)std::cout   << std::endl;
  }
  
}

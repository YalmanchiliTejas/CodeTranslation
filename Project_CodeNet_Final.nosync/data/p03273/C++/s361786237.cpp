#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;
using ll=long long;
#define mod  1000000007

int main(int argc, char const *argv[]) {
  int h,w;
  std::cin >> h >> w;

  char s[h][w];
  int gyou[h],retsu[w];
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      std::cin >> s[i][j];
      retsu[j]=0;
    }
    gyou[i]=0;
  }

  //行について
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(s[i][j]!='.') gyou[i]=1;
    }
  }
  //列について
  for(int i=0; i<w; i++){
    for(int j=0; j<h; j++){
      if(s[j][i]!='.') retsu[i]=1;
    }
  }

  for(int i=0; i<h; i++){
    if(gyou[i]==1){
    for(int j=0; j<w; j++){
      if( retsu[j]==1) std::cout << s[i][j] ;
      }
      printf("\n");
    }
    
  }


  return 0;
}

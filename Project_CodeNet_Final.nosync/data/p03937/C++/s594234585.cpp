#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

typedef long long ll;
#define fi first
#define se second


using namespace std;

int main(){
  
  int H, W;
  cin>>H>>W;
  
  int cnt = 0;
  
  char S[H][W+1];
  
  int i;
  int j;
  
  for( i = 0; i < H; i++){
    scanf("%s", S[i]);
  }
  
  for( i = 0; i < H; i++ ){
    for( j = 0; j < W; j++ ){
      if( S[i][j] == '#' ) cnt++;
    }
  }
  
  if( cnt == H+W-1 ) puts("Possible");
  else{              puts("Impossible");}
  
  return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int ans[16][16];
void init(){
  for(int i = 0; i < 16; i++){
    for(int j = 0; j < 16; j++){
      ans[i][j] = -1;
    }
  }
}

bool isfull(int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(ans[i][j] == -1){
	return true;
      }
    }
  }
  return false;
}

int main(){
  int n;
  int count = 1;
  int x,y;
  while(true){
    cin >> n;
    if(!n){
      break;
    }
    init();
    count = 1;
    x = n / 2;
    y = n / 2 + 1;
    ans[y][x] = count;
  
    count ++;
    y++;
    x++;
    while(isfull(n)){
      if(x == n){
	x = 0;
      }
      if(y == n){
	y = 0;
      }
      
      if(ans[y][x] == -1){
	ans[y][x] = count;
	count ++;
	y++;
	x++;
      }
      else{
	while(ans[y][x] != -1){
	  y++;
	  x--;
	  if(y == n){
	    y = 0;
	  }
	  if(x < 0){
	    x = n -1;
	  }
	}
	ans[y][x] = count;
	count ++;
	y++;
	x++;
      }
    }
    
    for(int i = 0;i < n;i++){
      for(int j=0;j<n;j++){
	printf("%4d",ans[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
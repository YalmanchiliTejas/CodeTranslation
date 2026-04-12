#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,fig,x,y;
bool used[16][16];
int mas[16][16];

bool check(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      if(!used[i][j]) return true;
  }
  return false;
}

void Over_R(); void Over_L(); void Over_U();

void Over_R(){
  x = 0;
  while(used[y][x]){
    y++; x--;
    if(x < 0) Over_L();
    if(y >= n) Over_U();
  }
}

void Over_L(){
  x = n-1;
  while(used[y][x]){
    y++; x--;
    if(x < 0) Over_L();
    if(y >= n) Over_U();
  }
}

void Over_U(){
  y = 0;
  while(used[y][x]){
    y++; x--;
    if(x < 0) Over_L();
    if(y >= n) Over_U();
  } 
}

int main(){
  while(cin >> n,n){
    memset(used,false,sizeof(used));
    fig = 2;
    x = n/2; y = n/2 + 1;
    mas[y][x] = 1; used[y][x] = true;
    while(check()){
      x++; y++;
      if(x >= n) Over_R();
      if(y >= n) Over_U();
      while(used[y][x]){
	x--; y++;
	if(x < 0) Over_L();
	if(y >= n) Over_U();
      }
      mas[y][x] = fig;
      fig++; used[y][x] = true;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++) printf("%4d",mas[i][j]);
      cout << endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
  int H, W;
  cin >> H >> W;
  string a[H];
  for(int i = 0;i < H;i++) cin >> a[i];
  
  int w[W] = {};
  for(int i = 0;i < W;i++){
    int cnt = 0;
    for(int j = 0;j < H;j++){
  if(a[j].at(i) == '.')
    cnt++;
    }
    if(cnt == H) w[i] = 1;
  }
  
  int h[H] = {};
    for(int i = 0;i < H;i++){
    int cnt = 0;
    for(int j = 0;j < W;j++){
  if(a[i].at(j) == '.')
    cnt++;
    }
    if(cnt == W) h[i] = 1;
  }
  
  for(int i = 0;i < H;i++){
    if(h[i] == 1) cout << "";
    else for(int j = 0;j < W;j++){
    if(w[j] == 1) cout << "";
      else cout << a[i].at(j);
      
      if(j == W - 1) cout << endl; 
    }
  }
  
  return 0;
  
}
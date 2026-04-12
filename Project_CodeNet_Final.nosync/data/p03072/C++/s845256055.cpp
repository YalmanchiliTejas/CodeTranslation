#include <bits/stdc++.h>

int main(){
  int i,j;
  int max;
  int n=0; //海を眺められる旅館の数
  
  int N;
  std::cin >> N; //山の数を決定
  
  int H[N];
  for(i=0;i<N;i++){
    std::cin >> H[i];
  }
  
  for(i=0;i<N;i++){
    if(i==0){
      n++; //一番西の旅館は海を眺められる
    }
    else{
      max=H[i];
      for(j=0;j<i;j++){
        if(max<H[j]){
          max=H[j];
        }
      }
      if(max==H[i]){
        n++;
      }
    }
  }
  std::cout << n << std::endl;
}
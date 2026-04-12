#include <stdio.h>
#include <iostream>

int main(int argc, char* argv[]){
  int sum=1;

  int n;
  std::cin >> n;
  int a[n];
  for(int i=0; i<n; i++) std::cin >> a[i];
  
  for(int i=1; i<n; i++){
    if(a[0]<=a[i]){
      sum++;
      a[0]=a[i];
    }
  }
  
  printf("%d",sum);
}
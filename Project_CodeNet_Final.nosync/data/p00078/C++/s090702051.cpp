#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace::std;

int main(){

  int number;
  int i, j;
  int center = 0;
  int h = 0;
  int w = 0;
  cin>>number;

  while(number != 0){
  int magic[number][number];

  for(i = 0; i < number; i++){
    for(j = 0; j < number; j++){
      magic[i][j] = -1;
    }
  }

  center = number/2;

  h = center + 1;
  w = center;
  magic[h][w] = 1;
  for(i = 2; i <= number * number; i++){
    h = (h + 1) % number;
    w = (w + 1) % number;
    if(magic[h][w] != -1){
      h = (h + 1) % number;
      w = w - 1;
      if(w == -1){
        w = w + number;
      }
    }
    magic[h][w] = i;
  }

  for(i = 0; i < number; i++){
    for(j = 0; j < number; j++){
      printf("%4d", magic[i][j]);
    }
    printf("\n");
  }



  cin>>number;
  }


  return 0;
}
#include<iostream>
#include<cstring>
#include <cmath>
#include<stdio.h>
using namespace std;
int main(){
  int x, y;
  cin >> x >> y;
  char arr[x][y];
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      cin >> arr[i][j];
    }
  }
  int index[x];
  int in1=0;
  int in2=0;
  int index2[y];
  for(int i=0; i<x; i++){
    int count1=0;
    for(int j=0; j<y; j++){
      if(arr[i][j]=='.') count1++;
    }
    if(count1==y) index[in1++]=i;
  }
  for(int j=0; j<y; j++){
    int count1=0;
    for(int i=0; i<x; i++){
      if(arr[i][j]=='.') count1++;
    }
    if(count1==x) index2[in2++]=j;
  }
  for(int i=0; i<x; i++){
    bool d3=false;
    for(int j=0; j<y; j++){
      bool de=true;
      bool de1=true;
      for(int x=0; x<in1; x++){
        if(index[x]==i){
          de=false;
          break;
        }
      }
      for(int x=0; x<in2; x++){
        if(index2[x]==j){
          de=false;
          break;
        }
      }
      
      if(de && de1){
        cout << arr[i][j];
        d3=true;
      }
    }
    if(d3)cout << "\n";
  }
  

}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin >> x >> y >> z;
  int sum=z;
  int i,count=0;
  for(i=0;i<x;i++){
      sum+=z+y;
    if(x>=sum){
      count++;
    }else{
      break;
    }
  }
  cout << count;
}
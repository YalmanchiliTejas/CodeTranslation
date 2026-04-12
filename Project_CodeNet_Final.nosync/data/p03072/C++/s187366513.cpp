#include <bits/stdc++.h>
using namespace std;
int main(){
  int i;
  int a;
  int out = 0;
  int mountainHeight[25];
  int mountainAmount;
  cin>>mountainAmount;
  for (i=0;i<mountainAmount;i++){
    cin>>mountainHeight[i];
  }
  a = mountainHeight[0];
  for (i=0;i<mountainAmount;i++){
    if(mountainHeight[i] < a){
    } else {
      out++;
      a = mountainHeight[i];
    }
  }
  cout<<out;
}
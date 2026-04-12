#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
int main(){
  map<char,int> store;
  char s;
  int i;
  for(i=0;i<3;i++){
    scanf("%c",&s);
    store[s]=1;
  }
  if(store['A']==1 && store['B']==1){
    printf("Yes\n");
  }
  else{
    printf("No\n");
  }
  return 0;
}
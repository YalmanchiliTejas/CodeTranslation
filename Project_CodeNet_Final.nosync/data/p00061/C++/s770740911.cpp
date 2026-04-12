#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
  pair<int,int> fun[100];
  int num,acc,tel,i=0,tmp;
  int j,z;
  while(1){
    scanf("%d,%d",&num,&acc);
    if(num == 0 && acc == 0) break;
    fun[i] = make_pair(acc,num);
    i++;
  }
  sort(fun,fun+i);
  tmp = fun[i-1].first;
  j = 1;
  fun[i-1].first = j;
  for(z=i-2;z>=0;z--){
    if(tmp == fun[z].first){
      fun[z].first = j;
    }
    else{
      j++;
      tmp = fun[z].first;
      fun[z].first = j;
    }
  }
  while(cin >> tel){
    for(j=0;j<i;j++){
      if(fun[j].second == tel){
	cout << fun[j].first << endl;
      }
    }
  }
}
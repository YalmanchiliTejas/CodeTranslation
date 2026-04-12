#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N;
  int ans = 1;
  vector<int> list;
  

  cin >>N;

  for(int i = 0; i< N ;i++){
    int x;
    cin >>x;
    list.push_back(x);
  }

  for(int i = 1; i< N ;i++){
    int flg = 0;
    for(int j = 0;j<i;j++){
      if(list[j] > list[i] )flg=1;
    }
    if(flg == 0)ans++;
  }

  cout <<ans<<endl;




  return 0;
  }
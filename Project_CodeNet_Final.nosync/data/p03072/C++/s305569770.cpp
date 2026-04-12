#include<iostream>
#include<string>
#include<algorithm>
#include <stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<array>
#include<vector>
#include<set>
#include <utility>
#include <map>
using namespace std;

int main(){
  int n; cin >>n;
  int h[200];
  for(int i=0;i<n;i++)
  cin >>h[i];
  int cnt=1;

  for(int i=1;i<n;i++){
    int a=h[i];
    int f=0;
    for(int j=0;j<i;j++){
      if(h[j]>a) {f=1; break;}
    }
    if(f==0) cnt++;
  }
   cout<<cnt<<endl;
  }

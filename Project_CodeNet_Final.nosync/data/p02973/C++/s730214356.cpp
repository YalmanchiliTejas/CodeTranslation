#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;


int main(){
long long a;
long long N;
cin>>N;
long long upper,lower,mid;
long long colors[N+100];
long long num_color=1;
cin>>a;
colors[0]=a;
for(long long j=1;j<N;++j){
  cin>>a;
  if(colors[num_color-1]>=a){
    colors[num_color]=a;
    num_color+=1;
    continue;
  }
  //upperはダメなとこギリギリ
  if(colors[0]<a){
    colors[0]=a;
    continue;
  }
  upper=0;
  //lowerは絶対いけるところ
  lower=(num_color-1);
  while(upper+1<lower){
    mid=(upper+lower)/2;
    //midが条件を満たさない場合
    if(colors[mid]>=a){
      upper=mid;
    }
    else{
      lower=mid;
    }
  }
  colors[lower]=a;
}
cout<<num_color<<"\n";
return 0;
}
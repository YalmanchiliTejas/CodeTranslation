#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int sum,r,g,b;
  sum=0;
  cin>>r>>g>>b;
  sum=r*100+g*10+b;
  if(sum%4==0){
	cout<<"YES";
  }else{
    cout<<"NO";
  }
    return 0;
}
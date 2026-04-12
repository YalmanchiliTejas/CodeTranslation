#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>
#include<stdio.h>


using namespace std;
typedef long long ll;
int input(){
  int x;
  cin>>x;
  return x;
}
int abs(int x){
  if(x>=0){
    return x;
  }else{
    return -x;
  }
}
int gcd(int x, int y){
	if(x<y){
    return gcd(y,x);
  }
  if(y==0){
    return x;
  }
  return gcd(y,x%y);
}
int moji(char in)
{
    int ans = (int)in-(int)'a'+1;
    if((in < 1) || (in > 26)){
        ans = 100;
    }
    return ans;
}







int main() {
  int X,Y,Z;
  cin>>X>>Y>>Z;
  int sum=0;
  X-=Y+2*Z;
  sum++;
  while(X>=Y+Z){
    sum++;
    X-=Y+Z;
  }
  cout<<sum<<endl;
  
  
}


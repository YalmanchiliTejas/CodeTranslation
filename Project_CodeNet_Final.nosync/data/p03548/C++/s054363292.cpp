#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int X,Y,Z;
  cin >>X>>Y>>Z;
  int tmp=1;
  while(Y*(tmp+1)+Z*(tmp+2)<=X){
    tmp+=1;
  }
  cout <<tmp<<endl;
}

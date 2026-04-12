#include<bits/stdc++.h>
using namespace std;
int main(){
  int X,Y,Z,a;
  cin>>X>>Y>>Z;
  for(int i=0;i<50000;i++){
    if(i*Y+(i+1)*Z<=X&&(i+1)*Y+(i+2)*Z>X){cout<<i<<endl;exit(0);
  }
  }
}
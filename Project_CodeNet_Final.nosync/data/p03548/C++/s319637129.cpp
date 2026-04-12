#include<bits/stdc++.h>
using namespace std;

int main(){
  long int x,y,z;
  cin>>x>>y>>z;
  long int t=x/y;
  while(t){
    if(x-t*y>=(t+1)*z) { cout<<t; return 0; }
    t--;
  }

}

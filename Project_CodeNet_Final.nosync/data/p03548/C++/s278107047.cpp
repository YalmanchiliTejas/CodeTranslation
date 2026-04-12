#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int x,y,z;cin>>x>>y>>z;
  int n=0;
  while(x>=y*n+(n+1)*z){
    n++;
  }
  cout<<n-1<<endl;
  return 0;
}

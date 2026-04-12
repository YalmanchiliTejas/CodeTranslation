#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,array[101],c,i=0,d;
  cin>>a>>b>>c;
  a-=c;
  while(a>=0){
    a-=b+c;
    i++;
  }
  cout<<i-1<<endl;
}
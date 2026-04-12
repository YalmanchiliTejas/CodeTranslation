#include<bits/stdc++.h>
using namespace std;
int main(void){
  int x,y,z;
  cin>>x>>y>>z;
  int width=y+z;
  int person=x/width;
  x-=(person*width);
  if(x<z)person--;
  cout<<person<<endl;
  return 0;
}
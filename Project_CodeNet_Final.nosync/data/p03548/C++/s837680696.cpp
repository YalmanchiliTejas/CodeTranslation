#include <bits/stdc++.h>
#include <map> // pair
using namespace std;

int main(){
  int X,Y,Z;
  cin>>X>>Y>>Z;
  int num =X/(Y+Z);
  if(X-num*(Y+Z)<Z)num-=1;

  cout<<num<<endl;
}

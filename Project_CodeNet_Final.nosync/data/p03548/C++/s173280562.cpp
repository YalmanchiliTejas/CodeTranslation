#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X,Y,Z;
  cin>>X>>Y>>Z;
  int count = 0;
  X-=Z;
  while(X>=Y+Z){
    count++;
    X -= Y;
    X -= Z;
    
  }
  cout<<count<<endl;
}
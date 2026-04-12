#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin >> x >> y >> z;
  for(int i=x/y;i>0;i--){
    if(i*(y+z)+z<=x){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
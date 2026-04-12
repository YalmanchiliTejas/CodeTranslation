#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int a=x/(y+z);
    if(a*(y+z)+z==x){
    cout << a << endl;
  }
  else if(a*(y+z)+z!=x){
  cout << a-1 << endl;
}
}
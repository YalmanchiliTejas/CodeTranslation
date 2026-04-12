#include <bits/stdc++.h>
using namespace std;
int main(){
  int r , g, b;
  cin >> r >> g >> b;
  int k = 10*g + b;
  if(0==k%4){
    cout<<"YES"<<endl;
  }
  else cout<<"NO"<<endl;
}

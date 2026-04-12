#include<bits/stdc++.h>

using namespace std;

int main(){
  string a; cin >> a;
  if((a[0]==a[1] && a[0]!=a[2])
  || (a[1]==a[2] && a[0]!=a[1])
  ||(a[0]==a[2] && a[0]!=a[1]))
  {cout << "Yes";}
  else{cout << "No";}

return 0;
}
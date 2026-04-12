#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  a=a*10+b;
  a=a*10+c;
  if(a%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
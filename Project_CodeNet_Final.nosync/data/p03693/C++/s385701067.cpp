#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c,k;
  cin >> a >> b >> c;
  k = b * 10 + c;
  if(k % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
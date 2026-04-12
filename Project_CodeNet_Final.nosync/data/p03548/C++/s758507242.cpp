#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() {
  
  ll A ,X, Y, Z;
  cin >> X >> Y >> Z;
  
  for (ll i = 0; i<10000000000000; i++) {
    A=Y*i+Z*(i+1);
  if(A>X){cout<<i-1;break;}}
}
    
   
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  string d = a + b + c;
  
  auto num = atoi(d.c_str());
  
  if(num%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}

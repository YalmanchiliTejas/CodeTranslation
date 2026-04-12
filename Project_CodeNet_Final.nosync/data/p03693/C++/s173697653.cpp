#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int x,a,b; cin >>x>>a>>b;
  if((10*a + b) % 4== 0){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
}
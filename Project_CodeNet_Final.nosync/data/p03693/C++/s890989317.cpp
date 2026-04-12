#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int x = a*100 + b*10 + c;
  if(x%4 == 0) cout << "YES";
  else cout << "NO";
  return 0;
}
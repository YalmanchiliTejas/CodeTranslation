#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  if((a*100+b*10+c)%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

//最大公約数
int gcd(int x, int y){
  if(x % y == 0) return 1;
  return gcd(y, x % y);
}

//最小公倍数
int lcm(int x, int y){
  return x * y / gcd(x, y);
}



int main(){
  int n, m;
  cin >> n >> m;
  if(n == m) cout <<"Yes" << endl;
  else cout << "No" << endl;
}

 
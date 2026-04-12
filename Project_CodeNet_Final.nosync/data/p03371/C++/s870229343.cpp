#include<bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(nullptr);ios_base::sync_with_stdio(false);
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int n = a * x + b * y;

  int m = 2 * c * max(x, y);

  int p = x < y ? b : a;

  int l = 2 * c * min(x, y) + p * abs(x - y);

  cout<<min(n, min(m, l))<<endl;
}
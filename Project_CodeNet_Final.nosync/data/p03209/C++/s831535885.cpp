#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long lint;
lint get_paty(int n, lint x, vector<lint> a, vector<lint> p)
{
  if(n == 0){
    if(x < 1)
      return 0;
    else
      return 1;
  }
  if(x == 1){
    return 0;
  }
  if(x <= 1 + a[n-1]){
    return get_paty(n-1, x-1, a, p);
  }
  else if(x == 2 + a[n-1]){
    return 1 + p[n-1];
  }
  else if(x <= 2 + 2 * a[n-1]){
    return 1 + p[n-1] + get_paty(n-1, x-2-a[n-1], a, p);
  }
  else if(x == 3 + 2 * a[n-1]){
    return 1 + 2 * p[n-1];
  }
}

int main(void)
{
  lint N, X;
  cin >> N >> X;
  vector<lint> a(N);
  vector<lint> p(N);
  a[0] = 1;
  p[0] = 1;
  for(int i = 1; i < N; i++){
    a[i] = 3 + 2 * a[i-1];
    p[i] = 1 + 2 * p[i-1];
  }
  cout << get_paty(N, X, a, p) << endl;;
  return 0;
}

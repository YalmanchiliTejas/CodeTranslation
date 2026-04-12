#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long a, b;
  a = b = 0;
  long long f, g;
  f = g = 0;
  vector<int> c(n), d, e;
  for(int i = 0; i < n; i++)
    cin >> c[i];
  sort(c.begin(), c.end());
  if(n % 2 == 0){
    for(int i = 0; i < n; i++){
      if(i * 2 < n)
        d.push_back(c[i]);
      else
        e.push_back(c[i]);
    }
    for(int i = 0; i < n / 2; i++){
      a += e[i];
      b += d[i];
      if(i != 0)
        a += e[i];
      if(i != n / 2 - 1)
        b += d[i];
    }
    cout << a - b << endl;
    return 0;
  }
  for(int i = 0; i < n; i++){
    if(i < n / 2){
      a += c[i] * 2;
      b += c[i] * 2;
    }
    else{
      f += c[i] * 2;
      g += c[i] * 2;
    }
  }
  f -= c[n / 2];
  f -= c[n / 2 + 1];
  b -= c[n / 2 - 1];
  b += c[n / 2];
  g -= c[n / 2] * 2;
  cout << max(f - a, g - b) << endl;
}

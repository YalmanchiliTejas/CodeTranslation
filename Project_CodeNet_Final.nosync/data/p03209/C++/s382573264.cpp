#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define ERROR 0
ll func(int n, ll x);
ll a[51], p[51];

int main() {
  int n;
  ll x, sum;
  cin >> n >> x;
  
  a[0] = 1, p[0] = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = 2*a[i-1]+3;
    p[i] = 2*p[i-1]+1;
  }

  sum = func(n, x);
  cout << sum << endl;
  return 0;
}

ll func(int n, ll x) {
  if (n==0) return x>0;
  if(x == 1) return 0;
  else if(1 < x && x <= 1+a[n-1]) return func(n-1, x-1);
  else if(x == 2+a[n-1]) return p[n-1]+1;
  else if(2+a[n-1] < x && x <= 2+2*a[n-1]) return (p[n-1]+1)+func(n-1, x-a[n-1]-2);
  else if(x == a[n]) return p[n];
  else return ERROR;
}

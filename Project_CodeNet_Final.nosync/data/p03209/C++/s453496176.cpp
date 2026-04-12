#include <iostream>
using namespace std;

long long int a[100], p[100];

long long int func(long long int n, long long int x){
  if(n==0) {
      if(x>0) return 1;
      else return 0;
  }else if(1 < x && x <= 1 + a[n-1]){
    return func(n-1, x-1);

  }else if(x == 2 + a[n-1]){
    return p[n-1] + 1;

  }else if(2+a[n-1] < x && x <= 2+2*a[n-1]){
    return p[n-1] + 1 + func(n-1, x-2-a[n-1]);

  }else if(x == 3+2*a[n-1]){
    return 2*p[n-1] + 1;
  }
}

int main() {
  long long int n, x;
  long long int ans;
  cin >> n >> x;
  a[0] = p[0] = 1;
  for(int i=1; i<=n; i++){
    a[i] = 2*a[i-1]+3;
    p[i] = 2*p[i-1]+1;
  }
  ans = func(n, x);
  cout << ans << endl;
}
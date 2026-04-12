#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>

using namespace std;

int main(){
  int n ; cin>> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  long long x = 0, y = 0;
  if(n % 2){
    for(int i = 0; i < (n-1)/2-1 ; i++){
      x += a[i] * 2;
    }
    for(int i = 0; i < (n-1)/2 ; i++){
      y += a[i] * 2;
    }
    x += a[(n-1)/2-1] + a[(n-1)/2];
    y -= a[(n-1)/2] + a[(n-1)/2+1];
    for(int i = (n-1)/2+1; i < n; i++){
      x -= a[i] * 2;
    }
    for(int i = (n-1)/2+2; i < n; i++){
      y -= a[i] * 2;
    }
    cout << max(x, y) << endl;
  }
  else{
    for(int i = 0; i < n/2-1; i++){
      x += a[i] * 2;
      y += a[i] * 2;
    }
    x += a[n/2-1] - a[n/2];
    y += a[n/2] - a[n/2-1];
    for(int i = n/2+1; i < n; i++){
      x -= a[i] * 2;
      y -= a[i] * 2;
    }
    cout << max(x, y) << endl;
  }
  return 0;
}

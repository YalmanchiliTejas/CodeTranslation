#include <iostream>
#include <vector>
using namespace std;


int main()
{
  int n;
  cin >> n;
  long a[n];
  for(int i = 0; i<n; ++i) cin >> a[i];
  long r = 1e9 + 7;
  long sum = 0;
  for(int i = 0; i<n; ++i){
    sum+=a[i];
  }
  sum %= r;
  sum = (sum * sum) % r;
  
  long s;
  for(int i = 0; i<n; ++i){
    s = a[i]*a[i];
    s %= r;
    sum -= s;
    if(sum < 0) sum+=r;
  }
  if(sum % 2 == 0) sum /= 2;
  else sum = (sum + r)/2;
  cout << sum << endl;
}

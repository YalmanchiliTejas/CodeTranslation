#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <vector>
#define rep(i,n) for( int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
  ll  n;
  cin >> n;
	ll a[n];
	rep(i,n) cin >> a[i] ;
  
  ll sum = 0;
	for( int i=0; i<n; i++){
		sum += a[i];
  }
  ll ans = 0;
  ll tmp1 = 0;
  ll tmp2 = 0;
	for( int i=0; i<n-1; i++){
    sum -= a[i];
		tmp1 = sum%(1000000000+7);
		tmp2 = a[i]%(1000000000+7);
		ans += tmp1*tmp2;
		ans = ans%(1000000000+7);
  }
	cout << ans << endl;
  

  return 0;
}

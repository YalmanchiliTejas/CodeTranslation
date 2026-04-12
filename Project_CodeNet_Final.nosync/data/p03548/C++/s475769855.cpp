#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
#define pie 3.141592653589793
#define si(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define ll long long
using namespace std;
int main()
{
  ll a,b,c;
  cin >> a >> b >> c;
  a-=2*c;
  ll ans = (a+c)/(b+c);
  cout << ans << endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long int llint;

int main()
{
  int a, b, c;
  int x, y;

  cin>> a >> b >> c >> x >> y;

  if(a + b <= c * 2) {
    cout<< a * x + b * y <<endl;
  } else {
    int cnt = 0;
    int big, sml, price;
    if(x > y) big = x, sml = y, price = a;
    else      big = y, sml = x, price = b;
    
    cnt += sml * c * 2;
    if((big - sml) * price < (big - sml) * c * 2) cnt += (big - sml) * price;
    else cnt += (big - sml) * c * 2;
    
    cout<< cnt <<endl;
  }
    

  return 0;
}

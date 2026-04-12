#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int uq(int div,int mod){
  if(mod == 0){
    return div;
  }
  return uq(mod,(div % mod));
}

int main()
{
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int sum = 0;
  int r = 1001001001;

  for(int i = 0; i <= max(x,y) * 2;){
    sum = 0;
    sum += i * c;
    //cout << sum << " ";
    if(x - i / 2 > 0){
      sum += (x - i / 2) * a;
    }
    //cout << sum << " ";
    if(y - i / 2 > 0){
      sum += (y - i / 2) * b;
    }
    //cout << sum << " ";
    r = min(r,sum);
    //cout << r << endl;
    i += 2;
  }

  cout << r << endl;
  return 0;
}
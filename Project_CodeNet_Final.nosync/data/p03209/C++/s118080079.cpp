#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll p[51], s[51];

int main()
{
  ll n, x;
  cin >> n >> x;

  p[0] = 1, s[0] = 1;
  for(int i = 1; i <= 50; i++){
    p[i] = p[i-1]*2 + 1;
    s[i] = s[i-1]*2 + 3;
  }

  ll ans = 0;
  while(n > 0){
    if(s[n] == x){
      ans += p[n];
      break;
    }else if(s[n]/2-n+1 <= x){
      ans += p[n-1];
      if(s[n]/2 < x){
        ans++;
        x--;
      }
      x -= s[n]/2;
    }else{
      x--;
    }
    n--;
  }

  cout << ans << endl;

  return 0;
}

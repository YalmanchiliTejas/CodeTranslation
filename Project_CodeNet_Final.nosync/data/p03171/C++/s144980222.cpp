#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MX = 3005;
ll d[MX][MX];
ll a[MX];

int main(){
  int n; scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%lld", a+i);
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i+1;j++){
      if( (n-i)%2 == 0){
        d[i][j] = max(a[j]+d[i-1][j+1], a[j+i-1]+d[i-1][j]);
      }
      else{
        d[i][j] = min(-a[j]+d[i-1][j+1], -a[j+i-1]+d[i-1][j]);
      }
    }
  }
  cout << d[n][1];
  return 0;
}

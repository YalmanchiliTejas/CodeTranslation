#include<bits/stdc++.h>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
#define SORT(c) sort((c).begin(),(c).end())
#define MOD 1000000007 //S(vector).size()
using namespace std;
typedef long long ll;

int main(void){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = MOD;
  for(int i = 0; i <= max(x, y) * 2; i += 2){
    int num_A = max(0, x - i / 2);
    int num_B = max(0, y - i / 2);
    ll sum = num_A * a + num_B * b + i * c;
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}

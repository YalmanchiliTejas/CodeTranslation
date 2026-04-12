#include <iostream>
using namespace std;
typedef long long ll;
const int N = 52;
ll n, x;
ll p[N], layer[N];
ll cnt;
ll get(ll curr, ll remain){
  if(remain <= curr) return 0;
  if(remain >= layer[curr] - curr) return p[curr];
  if(remain == layer[curr-1] + 2){
    return p[curr-1] + 1;
  } else if(remain > layer[curr-1] + 2){
    ll ans = 0;
    ans += p[curr-1] + 1;
    ans += get(curr - 1, remain - layer[curr-1] - 2);
    return ans;
  } else {
    return p[curr] - get(curr, layer[curr] - remain);
  }
}
int main(){
  cin >> n >> x;
  p[0] = 1;
  layer[0] = 1;
  for(int i = 1; i <= n; i ++){
    p[i] = 2*p[i-1]+1;
    layer[i] = 2*layer[i-1] + 3;
  }
  //cout << layer[n] << " " << p[n] << endl;
  cout << get(n, x) << endl;
  return 0;
}
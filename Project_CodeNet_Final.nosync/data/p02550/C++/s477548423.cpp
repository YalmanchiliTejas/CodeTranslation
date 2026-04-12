#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll, ll> P;

struct edge {int to, cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll GCD(ll a, ll b){
  if(b==0) return a;
  else return GCD(b, a%b);
}

ll LCM(ll a, ll b){
  if(a<b) swap(a,b);
  return a/GCD(a,b)*b;
}

int main(){
  ll n, m, x;
  cin >> n >> x >> m;
  int cycle, start;
  ll tmp = x;
  vector<ll> vec;
  vec.push_back(x);
  vector<bool> is_exist(m+1, false);
  is_exist[tmp] = true;
  ll ans = 0;
  for(int i=1; i<=m; i++){
    tmp *= tmp;
    tmp %= m;
    if(is_exist[tmp]){
      for(int j=0; j<i; j++){
        if(vec[j]==tmp){
          start = j;
          cycle = i-j;
          break;
        }
      }
      break;
    }
    is_exist[tmp] = true;
    vec.push_back(tmp);
  }
  if(n < start){
    for(int i=0; i<n; i++){
      ans += vec[i];
    }
    cout << ans << endl;
    return 0;
  }
  
  for(int i=0; i<start; i++){
      ans += vec[i];
  }
  n -= start;
  ll s_tmp = 0;
  for(int i=start; i<=start+cycle; i++){
    s_tmp += vec[i];
  }
  ans += s_tmp*(n/cycle);
  if(n%cycle>0){
    for(int i=start; i<start+n%cycle; i++){
      ans += vec[i];
    }
  }
  cout << ans << endl;
  return 0;
}

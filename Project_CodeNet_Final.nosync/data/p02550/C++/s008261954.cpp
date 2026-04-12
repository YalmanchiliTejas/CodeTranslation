#include <bits/stdc++.h>
 
#define TRACE(x) cerr << #x << " = " << x << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
#define SZ(x) (int)(x).size()
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
template<class Num>
Num mabs(Num A){
  if(A < 0) return -A;
  return A;
}

const int N = 1e5 + 10;

ll n;
int x, m;
int past[N];
int seq[N];

int main(){
  scanf("%lld %d %d", &n, &x, &m);
  ll ans = (ll)x;
  past[x] = 1;
  seq[1] = x;
  
  int last = x;
  
  int poc = 0;
  int i;
  for(i = 2; i <= n; i++){
    int next = (int)((ll)last * last % m);
    seq[i] = next;
    if(past[next] != 0){
      poc = past[next];
      break;
    }
    ans += (ll)next;
    past[next] = i;
    last = next;
  } 
  
  ll round_sum = 0ll;
  for(int j = poc; j < i; j++)
    round_sum += (ll)seq[j];
  
  if((ll)i != n){
    ll raz = n - (ll)i;
    ll cnt_rounds = raz / (ll)(i - poc);
    ans += round_sum * cnt_rounds;
    ll left = n - (ll)(i - 1) - cnt_rounds * (ll)(i - poc);
    for(int j = poc; left > 0; j++, left--){
      ans += seq[j];
    }
  }
  
  
  printf("%lld\n", ans);
  
  return 0;
}

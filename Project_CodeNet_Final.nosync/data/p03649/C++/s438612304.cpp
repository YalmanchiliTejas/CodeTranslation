#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  reverse(a,a+n);
  ll cmin = a[0];
  ll num = 1;
  ll ans = 0;
  rep1(i,n-1){
    if(cmin < n) break;
    ll dif = cmin - a[i];
    ll cnt_op = dif/(n+1);
    ll dec = (n - num + 1) * cnt_op;
    ll inc = num * cnt_op;
    rep(j,n){
      if(j<i) a[j] -= dec;
      else a[j] +=inc;
    }
    ans += cnt_op *num;
    // rep(j,n) cout << a[j] << " ";    
    // cout << endl;
    cmin = a[i];
    num++;
  }
  if(a[n-1]>=n){
    ans +=(a[n-1] - n)*n;
    rep(i,n){
      a[i] -= a[n-1] - n;
    }
  }
  // rep(j,n) cout << a[j] << " "; 
  // cout << endl;
  int idx_cmax = 0;
  while(a[idx_cmax]>=n){
    int nidx = idx_cmax;
    int nv = -1;
    rep(i,n){ 
      if(i==idx_cmax) a[i] -=n;
      else a[i]++;
      if(nv < a[i]){
        nidx = i;
        nv = a[i];
      }
    }
    idx_cmax = nidx;
    ans++;
  }
  cout << ans << endl;
  

  return 0;
    

}

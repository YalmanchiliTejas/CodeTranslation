#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(x)    (x).begin(),(x).end()
typedef long long ll;
const int MOD = (int)1e9 + 7;

string makeban(int left,string ban){
  if(left == 0) return ban;
  return makeban(left-1,"b" + ban + "p" + ban + "b");
}

ll solve(vector<ll> p, vector<ll> mid, vector<ll> len, int lv,ll x){
  if(lv == 1){
    string hoge = "bpppb";
    ll buf = 0;
    rep(i,x+1) if(hoge[i] == 'p') buf++;
    return buf;
  }
  if(x == 0)
    return 0;
  if(x == len[lv]-1)
    return p[lv];
  if(x == mid[lv])
    return p[lv-1] + 1;
  if(x < mid[lv])
    return solve(p,mid,len,lv-1,x-1);
  if(x > mid[lv])
    return solve(p,mid,len,lv-1,x-mid[lv]-1) + p[lv-1] + 1;
}

int main(){
  ll n,x;
  cin >> n >> x;
  /*
  if(n <= 0){
    int ans = 0;
    string ban = makeban(n,"p");
    rep(i,x) if(ban[i] == 'p') ans++;
    cout << ans << endl;
    return 0;
  }
  */
  vector<ll> p_max(n+1),mid(n+1),len(n+1);
  p_max[0] = 1;
  mid[0] = 0;
  len[0] = 1;
  rep(i,n){
    p_max[i+1] = 1 + p_max[i]*2;
    len[i+1] = 3 + len[i] * 2;
    mid[i+1] = 1 + len[i];
  }
  cout << solve(p_max,mid,len,n,x-1) << endl;
}


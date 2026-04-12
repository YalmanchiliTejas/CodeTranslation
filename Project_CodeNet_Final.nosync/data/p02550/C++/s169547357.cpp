#include <bits/stdc++.h>
using namespace std;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
 
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
const int MAX = 1000000;
const int MOD = 1000000007;
 
int main(){
  ll n, x, m, ans=0;
  cin >> n >> x >> m;
  map<ll, int>mp;
  vector<ll>bflp,lp;
  bool flag = true;
  ll loop = 0, sum = 0;
  ll p = x;
  while(flag){
    mp[p]++;
    if(mp[p]==3){
      mp[p]--;
      flag = false;
      break;
    }
    p = p*p;
    p%= m;
  }
  ll cnt1=0;
  for(auto i :mp){
    if(i.second==1){
      cnt1++;
      //bflp.push_back(i.first);
    }else{
      loop++;
      //lp.push_back(i.first);
    }
  }
  p = x;
  lrep(i, 0, cnt1){
    bflp.push_back(p);
    p = p*p%m;
  }
  lrep(i, 0, loop){
    lp.push_back(p);
    p = p*p%m;
  }
  ll q1 = lp.size();
  ll q2 = bflp.size();
  if(q2>n){
    lrep(i, 0, n){
      ans += bflp[i];
    }
    cout << ans << endl;
    return 0;
  }else{
    lrep(i, 0, q2){
      ans += bflp[i];
    }
  }

  lrep(i, 0, q1){
    sum += lp[i];
  }

  ll r= (n-q2)/loop;
  ans += r*sum;
  ll r2= (n-q2)%loop;
  ll test =0;
  lrep(i, 0, r2){
    ans += lp[i];
    test +=  lp[i];
  }
  cout << ans << endl;
  //cout << mp.size() << endl;
  //cout << q1 << " " << q2<< endl;
  //cout << r << " " << r2 << " " << loop << " " << sum << endl;
  //cout << test << endl;
  //rep(i, 0, q1)cout << lp[i]<<" ";
  //cout << endl;
}
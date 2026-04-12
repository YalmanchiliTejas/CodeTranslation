
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std; using ll=long long; const int INF=1e2; using P=pair<ll,ll>;

int main() {
  int n; cin>>n;

  /*
  const int n=8;
  P p[n];
  for(int i=0;i<n;i++) {
    p[i].first = r::nd((int)1e2);
    p[i].second = r::nd((int)1e2);
  }

  cout<<n<<endl;
  for(int i=0;i<n;i++) cout<<p[i].first<<" "<<p[i].second<<endl;
  */

  P p[n];

  for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
  for(int i=0;i<n;i++) if (p[i].first > p[i].second) swap(p[i].first, p[i].second);

  sort(p,p+n);

  ll x[n], y[n];
  for(int i=0;i<n;i++) x[i]=p[i].first, y[i]=p[i].second;

  multiset<ll> s1, s2;
  for(int i=0;i<n;i++) {
    s1.insert(x[i]);
    s2.insert(y[i]);
  }

  ll an=1e18;
  for(int i=0;i<n;i++) {
    ll xx = (*(s1.rbegin()) - *(s1.begin()));
    ll yy = (*(s2.rbegin()) - *(s2.begin()));
    //cout<<i<<" "<<*(s1.rbegin())<<" "<<*(s1.begin())<<" "<<*(s2.rbegin())<<" "<<*(s2.begin())<<endl;
    an = min(an, xx * yy);

    auto it1 = s1.find(x[i]); // 重複削除回避
    auto it2 = s2.find(y[i]);
    s1.erase(it1); s1.insert(y[i]);
    s2.erase(it2); s2.insert(x[i]);
  }
  cout<<an<<endl;
  /*

  an = 1e18;
  for(int i=0;i<(1<<n);i++) {
    ll mx1 = -1e9, mn1 = 1e9, mx2 = -1e9, mn2 = 1e9;
    for(int j=0;j<n;j++) {
      if (i & (1<<j)) {
        mx1 = max(mx1, x[j]); mn1 = min(mn1, x[j]);
        mx2 = max(mx2, y[j]); mn2 = min(mn2, y[j]);
      } else {
        mx1 = max(mx1, y[j]); mn1 = min(mn1, y[j]);
        mx2 = max(mx2, x[j]); mn2 = min(mn2, x[j]);
      }
    }
    if ((mx1 - mn1) * (mx2 - mn2) == 4365) {
      int ii=i; string str;
      while(ii>0) str+=to_string(ii%2), ii/=2;
      reverse(str.begin(), str.end());
      cout<<str<<" "<<mx1<<" "<<mn1<<" "<<mx2<<" "<<mn2<<endl;
    }
    an = min(an, (mx1 - mn1) * (mx2 - mn2));
  }
  cout<<an<<endl;
  */
}

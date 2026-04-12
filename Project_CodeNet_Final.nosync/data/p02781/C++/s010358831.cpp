#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  string s;
  getline(cin,s);
  vector<ll> v;
  ll l = s.size();
  for(int i = 0; i < l; i++){
    v.push_back((ll)(s[i]-'0'));
  }
  int K;
  cin>>K;
  ll ans = 0LL;
  if(K==1){
    ans+=9LL*(l-1LL)+v[0];
  }
  if(K==2&&l>=2){
    ans+=81LL*(l-1LL)*(l-2LL)/2LL+(v[0]-1LL)*(l-1LL)*9LL;
    int p = l-1LL;
    for(int i = 1; i < l; i++){
      if(v[i]!=0LL){
        p=i;
        break;
      }
    }
    ans+=9LL*(l-(p+1LL))+v[p];
  }
  if(K==3&&l>=3){
    ans+=9LL*9LL*9LL*(l-1LL)*(l-2LL)*(l-3LL)/6LL+(v[0]-1LL)*(l-1LL)*(l-2LL)*81LL/2LL;
    int p=l-1LL,q=l-1LL;
    for(int i = 1; i < l; i++){
      if(v[i]!=0LL){
        p=i;
        break;
      }
    }
    for(int i = p+1LL;i<l;i++){
      if(v[i]!=0LL) {
        q=i;
        break;
      }
    }
    ans+=81LL*(l-(p+1LL))*(l-(p+2LL))/2LL+(v[p]-1LL)*(l-(p+1LL))*9LL;
    ans+=9LL*(l-(q+1LL))+v[q];
  }
  cout<<ans<<endl;
}
  
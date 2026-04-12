#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n;
  cin >>n;
  deque<ll> g,r;
  vector<ll>p;
  ll ans=0;
  rep(i,n){
    ll a;
    cin >> a;
    p.push_back(a);
  }
  sort(p.begin(),p.end());
  rep(i,n){
    g.push_back(p.back());
    r.push_front(p.back());
    p.pop_back();
  }

  ll k=g.front();
  ll fir=k;
  g.pop_front();
  rep(i,n-1){
    if(i==n-2){
      ans+=max(abs(k-g.front()),abs(fir-g.front()));
    }
    else if((i+2)%2==0){
      ans+=abs(k-g.back());
      k=g.back();
      g.pop_back();
    }else{
      ans+=abs(k-g.front());
      k=g.front();
      g.pop_front();
    }
  }

  k=r.front();
  fir=k;
  r.pop_front();
  ll ans2=0;
    rep(i,n-1){
    if(i==n-2){
      ans2+=max(abs(k-r.front()),abs(fir-r.front()));
    }
    else if((i+2)%2==0){
      ans2+=abs(k-r.back());
      k=r.back();
      r.pop_back();
    }else{
      ans2+=abs(k-r.front());
      k=r.front();
      r.pop_front();
    }
  }

  cout << max(ans,ans2) << endl;
}

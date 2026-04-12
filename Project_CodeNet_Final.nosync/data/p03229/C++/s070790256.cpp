#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(all(a));
  deque<ll> de;
  deque<ll> de2;
  deque<ll> de3;
  deque<ll> de4;
  rep(i,n){
    de.push_back(a[i]);
    de3.push_front(a[i]);
  }
  int i=0;
  while(de.size()){
    if(i==0){
      de2.push_back(de.front());
      de.pop_front();
    }
    else if(i%2==1){
      de2.push_back(de.back());
      de.pop_back();
      if(de.empty()) break;
      de2.push_front(de.back());
      de.pop_back();
    }
    else{
      de2.push_back(de.front());
      de.pop_front();
      if(de.empty()) break;
      de2.push_front(de.front());
      de.pop_front();
    }
    i++;
  }
  i=0;
  while(de3.size()){
    if(i==0){
      de4.push_back(de3.front());
      de3.pop_front();
    }
    else if(i%2==1){
      de4.push_back(de3.back());
      de3.pop_back();
      if(de3.empty()) break;
      de4.push_front(de3.back());
      de3.pop_back();
    }
    else{
      de4.push_back(de3.front());
      de3.pop_front();
      if(de3.empty()) break;
      de4.push_front(de3.front());
      de3.pop_front();
    }
    i++;
  }
  ll ans1=0;
  while(de2.size()){
    ll a=de2.front();
    de2.pop_front();
    if(de2.empty()) break;
    ll b=de2.front();
    ans1+=abs(a-b);
  }
  ll ans2=0;
  while(de4.size()){
    ll a=de4.front();
    de4.pop_front();
    if(de4.empty()) break;
    ll b=de4.front();
    ans2+=abs(a-b);
  }
  cout << max(ans1,ans2) << endl;
}
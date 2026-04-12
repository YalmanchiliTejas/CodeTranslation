#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  deque<int> q;
  rep(i,n){
    if(i%2==1) q.push_front(a[i]);
    else q.push_back(a[i]);
  }
  if(n%2==0){
    rep(i,n){
      cout << q.front() << " ";
      q.pop_front();
    }cout << endl;
  }
  else{
    rep(i,n){
      cout << q.back() << " ";
      q.pop_back();
    }cout << endl;
  }
}
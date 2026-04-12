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
  multiset<int> st;
  reverse(all(a));
  rep(i,n){
    if(st.upper_bound(a[i])==st.end()){
      st.insert(a[i]);
    }
    else{
      st.erase(st.find(*st.upper_bound(a[i])));
      st.insert(a[i]);
    }
  }
  int ans=st.size();
  cout << ans << endl;
}
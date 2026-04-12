#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n;
  cin >> n;
  multiset<int> st;
  rep(i,n){
    int x;cin >> x;
    if(st.empty()){
      st.insert(x);
      continue;
    }
    auto iter = st.lower_bound(x);
    if(iter == st.begin()){
      st.insert(x);
    }else{
      iter--;
      st.erase(iter);
      st.insert(x);
    }
  }
  cout << st.size() << endl;



  return 0;
}
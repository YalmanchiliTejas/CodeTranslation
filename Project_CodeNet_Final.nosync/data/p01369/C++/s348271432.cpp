#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,x,n) for(int i=(x);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define int long long
using namespace std;
const int MOD=1e9+7;
const int INF=1e15;
template<typename T> void cmax(T &a, T b) {a = max(a, b);}
template<typename T> void cmin(T &a, T b) {a = min(a, b);}

signed main(){
  string t;
  set<char> s={'y','u','i','o','p','h','j','k','l','n','m'};

  while(cin>>t){
    if(t=="#")break;
    vector<int> a;
    rep(i,t.size()){
      if(s.count(t[i]))a.push_back(1);
      else a.push_back(0);
    }
    int ans=0;
    rep(i,a.size()-1){
      ans+=(a[i+1]^a[i]);
    }
    cout<<ans<<endl;


  }

 return 0;
}


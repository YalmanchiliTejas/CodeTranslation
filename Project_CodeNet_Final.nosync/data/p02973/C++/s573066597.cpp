#include <bits/stdc++.h>
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long long
#define fin {cout<<-1<<endl;return 0;}
//template
//main
signed main(){
  int N;cin>>N;
  map<int,int> s;
  s[-LINF]=1;
  typedef pair<int,int> P;
  for(int i=0;i<N;i++){
    int a;cin>>a;
    P p=*--s.lower_bound(a);
    if(p.first<0){
      s[a]++;
      continue;
    }
    s[p.first]--;if(s[p.first]==0)s.erase(p.first);
    s[a]++;
  }
  int ans=-1;
  for(auto q:s)ans+=q.second;
  cout<<ans<<endl;
}

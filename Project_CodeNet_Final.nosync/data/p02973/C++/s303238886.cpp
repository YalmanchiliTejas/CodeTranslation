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
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  reverse(v.begin(),v.end());
  typedef pair<int,int> P;
  set<P> s;
  s.insert(P(LINF,0));
  for(int i=0;i<N;i++){
    P p=*s.upper_bound(P(v[i],i));
    if(p.first<LINF)s.erase(p);
    s.insert(P(v[i],i));
  }
  cout<<s.size()-1<<endl;
}

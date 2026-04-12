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
  typedef pair<int,int> P;
  set<P> s;
  s.insert(P(-LINF,0));
  while(N--){
    int a;cin>>a;
    P p=*--s.lower_bound(P(a,N));
    if(p.first>=0)s.erase(p);
    s.insert(P(a,N));
  }
  cout<<s.size()-1<<endl;
}

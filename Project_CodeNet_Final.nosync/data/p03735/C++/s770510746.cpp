#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
const long long LINF=1e18;
template<typename T>
void chmin(T &a,T b){
  if(a>b)a=b;
}
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}

signed main(){
  int n;cin>>n;
  vector<P> b(n);
  int mx=0;
  for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    if(x>y)swap(x,y);
    chmax(mx,y);
    b[i]=P(x,y);
  }
  sort(b.begin(),b.end());
  int ans=LINF;
  int A=b[n-1].first-b[0].first;
  int B=LINF;
  for(int i=0;i<n;i++)chmin(B,b[i].second);
  chmin(ans,A*(mx-B));
  map<int,int> m;
  for(int i=0;i<n;i++)m[b[i].first]++;
  for(int i=0;i<n;i++){
    chmin(ans,(mx-b[0].first)*(m.rbegin()->first-m.begin()->first));
    m[b[i].second]++;
    if(--m[b[i].first]==0)m.erase(b[i].first);
  }
  chmin(ans,(mx-b[0].first)*(m.rbegin()->first-m.begin()->first));
  cout<<ans<<endl;
}

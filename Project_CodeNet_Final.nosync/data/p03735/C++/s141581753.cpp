#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
signed main(){
  int n;
  cin>>n;
  int x[n],y[n];
  for(int i=0;i<n;i++) cin>>x[i]>>y[i];
  int mi=min(*min_element(x,x+n),*min_element(y,y+n));
  int ma=max(*max_element(x,x+n),*max_element(y,y+n));
  int ans=1LL<<62LL;
  int r=mi,b=ma;
  for(int i=0;i<n;i++){
    if(x[i]>y[i]) swap(x[i],y[i]);
    r=max(r,x[i]);
    b=min(b,y[i]);
  }
  ans=min(ans,(r-mi)*(ma-b));
  //cout<<ans<<endl;
  vector<P> v;
  for(int i=0;i<n;i++){
    v.push_back(P(x[i],i));
  }
  sort(v.begin(),v.end());
  int ri=v[0].first,ra=v[n-1].first;
  int tmp=ra;
  for(int i=0;i<n-1;i++){
    //cout<<ra<<" "<<ri<<endl;
    ans=min(ans,(ma-mi)*abs(ra-ri));
    ra=max(ra,y[v[i].second]);
    ri=min(y[v[i].second],v[i+1].first);
    tmp=min(tmp,y[v[i].second]);
    if(tmp<=v[i+1].first){
      ri=tmp;
      break;
    }
    if(y[v[i].second]<=v[i+1].first) break;
    if(ri>=ra) break;
  }
  ans=min(ans,(ma-mi)*(ra-ri));
  cout<<ans<<endl;
  return 0;
}

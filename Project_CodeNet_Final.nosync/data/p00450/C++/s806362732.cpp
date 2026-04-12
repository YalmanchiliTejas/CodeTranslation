#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  while(cin>>n,n){
    int c[n];
    for(int i=0;i<n;i++) cin>>c[i];
    typedef pair<int,int> P;
    vector<P> v;
    v.push_back(P(-1,0));
    for(int i=0;i<n;i++){
      if(i%2==0){
	if(v.back().first==c[i]) v[v.size()-1].second++;
	else v.push_back(P(c[i],1));
      }else{
	if(v.back().first==c[i]) v[v.size()-1].second++;
	else{
	  int k=v.back().second;
	  v.pop_back();
	  if(v.back().first<0) v.push_back(P(c[i],k+1));
	  else v[v.size()-1].second+=k+1;
	}
      }
    }
    //for(P p:v) cout<<p.first<<" "<<p.second<<endl;
    int ans=0;
    for(P p:v) if(p.first==0) ans+=p.second;
    cout<<ans<<endl;
  }
  return 0;
}
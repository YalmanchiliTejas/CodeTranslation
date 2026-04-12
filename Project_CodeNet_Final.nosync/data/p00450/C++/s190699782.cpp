//20
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
 
using namespace std;
 
int main(){
  for(int n;cin>>n,n;){
    vector<pair<int,int> > v;
    for(int i=1;i<=n;i++){
      int c;
      cin>>c;
      if(i%2==0&&v.end()[-1].first!=c){
	if(v.size()==1){
	  v[0].first^=1;
	}else{
	  v.end()[-2].second+=v.end()[-1].second;
	  v.erase(v.end()-1);
	}
      }
      if(v.empty()||v.end()[-1].first==(c^1)){
	v.push_back(make_pair(c,1));
      }else{
	v.end()[-1].second++;
      }
    }
    int ans=0;
    for(int i=0;i<v.size();i++){
      if(v[i].first==0){
	ans+=v[i].second;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
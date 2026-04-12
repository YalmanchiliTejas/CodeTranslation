#include<bits/stdc++.h>
using namespace std;
typedef pair<int,vector<int> >P;
int main(){
  int n,m,ans=0;
  cin>>n>>m;
  int a,b;
  vector<int>mp[n+1],gg;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
  priority_queue<P,vector<P>,greater<P> >pq;
  gg.push_back(1);
  pq.push(P(1,gg));
  while(!pq.empty()){
    P now=pq.top();
    pq.pop();
    int cos=now.first;
    vector<int>sum=now.second;
    if(sum.size()==n){
      ans++;
    }else{
      for(int i=0;i<mp[cos].size();i++){
	int aaa=0;
	for(int j=0;j<sum.size();j++){
	  if(mp[cos][i]==sum[j]){
	    aaa=1;
	    break;
	  }
	}
	if(aaa==0){
	  vector<int>ex=sum;
	  ex.push_back(mp[cos][i]);
	  pq.push(P(mp[cos][i],ex));
	}
      }
    }
  }
  cout<<ans<<endl;
  return(0);
}

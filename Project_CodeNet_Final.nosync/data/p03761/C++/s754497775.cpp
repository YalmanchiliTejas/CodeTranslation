#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void fastIO(){
  ios_base::sync_with_stdio(0); cin.tie(0);
}


int main(){
  fastIO();
  int n;
  cin>>n;
  vector<string>head(n);
  vector<vector<int>>vis;
  for(int i=0;i<n;i++){
  	vector<int>fill;
  	vis.push_back(fill);
  	cin>>head[i];
  }
  int s = head[0].length();
  string h = head[0];
  vector<char>ans;
  for(int i=0;i<s;i++){
  	bool found = true;
  	for(int j=0;j<n;j++){
  		string s = head[j];
  		bool key = false;
  		for(int q=0;q<s.length();q++){
  			sort(vis[j].begin(),vis[j].end());
  			if(s[q]==h[i]&&!binary_search(vis[j].begin(),vis[j].end(),q)){
  				key=true;
  				vis[j].push_back(q);
  				break;
  			}
  		}
  		if(!key){
  			found=false;
  		}
  	}
  	if(found){
  		ans.push_back(h[i]);
  	}
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
  	cout<<ans[i];
  }
  cout<<endl;
}

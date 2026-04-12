#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int>h(n); for(auto&i:h)cin>>i;
	int mx=h.front(),ans=0;
	for(auto&i:h){
		mx=max(mx,i);
		if(i>=mx)++ans;
	}
	cout<<ans<<"\n"s;
}
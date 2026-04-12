#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	int n,x,m;
	cin>>n>>x>>m;
	vector<int>first(m,-1);
	vector<int>pre(2*m,0);
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(first[x]>=0){
			int loopsize = i-first[x];
			int loopsum = pre[i-1]-pre[first[x]-1];
			
			int loops = (n-i)/loopsize;
			
			ans += loops*loopsum;
			i+=loopsize*loops;
			for(int j=0;j<m;j++){
				first[j]=-1;
			}
		}
		if(i<pre.size()){
			pre[i]=pre[i-1]+x;
			first[x]=i;
		}
		
		ans += x;
		x = (x*x)%m;
	}
	
	cout<<ans<<endl;
}


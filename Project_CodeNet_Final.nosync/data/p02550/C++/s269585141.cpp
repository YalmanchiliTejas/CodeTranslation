#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,x,m,fix[100005],i,cycle,s,ans,k;
vector<int>V;
 main(){
	cin>>n>>x>>m;
	while(!fix[x] && n){
		i++; ans+=x; n--;
		fix[x]=i; 
		V.push_back(x);
		x=x*x%m; 
	} 
	if(!n) cout<<ans;
	else {
	//	cout<<ans<<" "<<n<<endl;
		i=fix[x];
		 cycle=V.size()-i+1; 
		for(int k=i-1;k<V.size();k++){
			s+=V[k];
		}
		ans+=(n/cycle)*s;//cout<<ans<<endl;
		n%=cycle;
		for(k=i-1;k<=i-1+n-1;k++){
			ans+=V[k];
		}
		cout<<ans;
	}
	
}
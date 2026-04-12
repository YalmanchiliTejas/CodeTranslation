#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
double y;
int n,m,o,t,x,z;
main(){
	cin>>n;
	while(n--){
		int ans=0;
		cin>>x>>t>>m;
		r(i,m){
			int s=0,p=x,a=0;
			cin>>o>>y>>z;
			r(i,t){
				if(o)p+=y*p;
				else a+=y*p;
				p-=z;
			}
			ans=max(ans,p+a);
		}
		cout<<ans<<endl;
	}
}
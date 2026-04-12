#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,l[50000];
int main(){
	while(cin>>n,n){
		int p=0,prev,t,ans=0;
		cin>>t,prev=t,l[p]=1;
		rep(i,n-1){
			cin>>t;
			if(prev==t)l[p]++;
			else{
				if(i&1)l[++p]=1;
				else p>0?(p--,l[p]+=l[p+1]+1):l[p]++;
			}
			prev=t;
		}
		rep(i,p+1)ans+=t+i&1?0:l[p-i];
		cout<<ans<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
const int inf=1145141919ll;
const int mod=1000000007ll;
const int dd[]={0,-1,0,1,0};
using namespace std;
int n,m,k;
int p[50];
signed main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>p[i];
	int ans=0,u=0;
	for(i=0;;i++){
		if(i==n)
			i=0;
		if(p[i]>=n){
			int x=p[i]/n;
			ans+=x;
			p[i]=p[i]%n;
			for(j=0;j<n;j++)
				if(j!=i)
					p[j]+=x;
			u=0;
		}else
			u++;
		if(u==50)
			break;
	}
	cout<<ans<<endl;
	return 0;
}
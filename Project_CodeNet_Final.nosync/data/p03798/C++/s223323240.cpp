#include<bits/stdc++.h>
using namespace std;
string st;
int main(){
	long long n,i,j,k,f[100010];
	cin>>n;
	cin>>st;
	for(i=0;i<=1;i++)
		for(j=0;j<=1;j++){
			f[0]=i;
			f[1]=j;
			for(k=1;k<=n-2;k++)
				f[k+1]=(st[k]=='o'?0:1)^f[k-1]^f[k];
			if(f[0]==((st[n-1]=='o'?0:1)^f[n-2]^f[n-1])&&f[n-1]==((st[0]=='o'?0:1)^f[0]^f[1])){
				for(i=0;i<=n-1;i++)cout<<(f[i]==1?'W':'S');
				return 0;
			}
		}
	cout<<-1;
	return 0;
}
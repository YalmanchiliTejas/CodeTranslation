#include<bits/stdc++.h>
using namespace std;
string dat;
bool zz[100010];
int main(){
	long long n,i,j,k;
	cin>>n>>dat;
	for(i=0;i<=1;i++)
		for(j=0;j<=1;j++){
			zz[0]=i;
			zz[1]=j;
			for(k=1;k<=n-2;k++)
				zz[k+1]=zz[k-1]^zz[k]^(dat[k]=='x');
			if((dat[n-1]=='x')==(zz[n-2]^zz[n-1]^zz[0])&&(dat[0]=='x')==(zz[n-1]^zz[0]^zz[1])){
				for(k=0;k<=n-1;k++)cout<<(zz[k]?'W':'S');
				cout<<'\n';
				return 0;
			} 
		}
	cout<<-1<<'\n';
	return 0;
}

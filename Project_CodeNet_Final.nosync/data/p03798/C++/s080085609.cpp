#include<bits/stdc++.h>
using namespace std;

int res[100005],n;
string s;

int main(){
	cin>>n>>s;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			res[0]=i;
			res[1]=j;
			bool flag=true;
			for(int k=2;k<n;k++) 
				res[k]=(s[k-1]!='o')^res[k-1]^res[k-2];
			for(int k=0;k<n;k++){
				int a=(k-1+n)%n,b=(k+1+n)%n;
				if(res[k]^(s[k]=='o')!=(res[a]==res[b])) flag=false;
			}	
			if(flag){
				for(int i=0;i<n;i++) cout<<(res[i]?'W':'S');
				return 0;
			}
		}
	cout<<-1;
	return 0;
}
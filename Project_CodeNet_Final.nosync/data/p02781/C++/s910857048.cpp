#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int Maxn=100;
ll f[Maxn+5][10][2];
char s[Maxn+5];
int n,k;
ll dfs(int n,int k,int flag){
	if(f[n][k][flag]!=-1){
		return f[n][k][flag];
	}
	if(n==0){
		if(k==0){
			return f[n][k][flag]=1;
		}
		return f[n][k][flag]=0;
	}
	f[n][k][flag]=0;
	if(flag>0){
		if(s[n]>'0'){
			if(k>0){
				f[n][k][flag]+=dfs(n-1,k-1,1);
				f[n][k][flag]+=(s[n]-'0'-1)*dfs(n-1,k-1,0);
			}
			f[n][k][flag]+=dfs(n-1,k,0);
		}
		else{
			f[n][k][flag]+=dfs(n-1,k,1);
		}
	}
	else{
		if(k>0){
			f[n][k][flag]+=9*dfs(n-1,k-1,0);
		}
		f[n][k][flag]+=dfs(n-1,k,0);
	}
	return f[n][k][flag];
}
void swp(char &a,char &b){
	char t=a;
	a=b;
	b=t;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1,j=n;i<j;i++,j--){
		swp(s[i],s[j]);
	}
	scanf("%d",&k);
	memset(f,-1,sizeof f);
	cout<<dfs(n,k,1)<<endl;
	return 0;
}

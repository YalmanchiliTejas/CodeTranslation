#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100005];
int ans[100005],n;
int check(){
	int flag=1,i;
	for(i=1;i<=n;i++){
		int l=i-1,r=i+1;
		if(l==0)l=n;
		if(r==n+1)r=1;
		if(ans[i]==1){
			if(s[i]=='o'&&ans[l]!=ans[r])return 0;
			if(s[i]=='x'&&ans[l]==ans[r])return 0;
		}
		else{
			if(s[i]=='o'&&ans[l]==ans[r])return 0;
			if(s[i]=='x'&&ans[l]!=ans[r])return 0;
		}
	}
	return 1;
}
void work(){
	for(int i=2;i<n;i++){
		if(ans[i]==1){
			if(s[i]=='o')ans[i+1]=ans[i-1];
			else ans[i+1]=(ans[i-1]==1?2:1);
		}
		else{
			if(s[i]=='o')ans[i+1]=(ans[i-1]==1?2:1);
			else ans[i+1]=ans[i-1];
		}
	}
}
int main(){
	int flag=0,i;
	scanf("%d",&n);
	scanf("%s",s+1);
	ans[1]=ans[2]=1;
	work();
	if(check()){
		for(i=1;i<=n;i++)printf("%c",ans[i]==1?'S':'W');
		printf("\n");
		return 0;
	}
	ans[1]=ans[2]=2;
	work();
	if(check()){
		for(i=1;i<=n;i++)printf("%c",ans[i]==1?'S':'W');
		printf("\n");
		return 0;
	}
	ans[1]=1;
	ans[2]=2;
	work();
	if(check()){
		for(i=1;i<=n;i++)printf("%c",ans[i]==1?'S':'W');
		printf("\n");
		return 0;
	}
	ans[2]=1;
	ans[1]=2;
	work();
	if(check()){
		for(i=1;i<=n;i++)printf("%c",ans[i]==1?'S':'W');
		printf("\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}
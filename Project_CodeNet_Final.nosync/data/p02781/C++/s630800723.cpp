#include<bits/stdc++.h>
using namespace std;
const int N=110;
char s[N];
int a[N];
int k,l,ans;
int c(int x,int y){
	if(y==0) return 1;
	else if(y==1) return x;
	else if(y==2) return (x*(x-1))/2;
	else if(y==3) return (x*(x-1)*(x-2))/6;
}
int find(int len,int x[],int t){
	if(t==0||len==0||t>len) return 0;
	if(t==1){
		if(x[len-1]==0) return find(len-1,x,t);
		else return x[len-1]+(len-1)*9;
	}
	if(t==2){
		if(x[len-1]==0) return find(len-1,x,t);
		else return (x[len-1]-1)*c(len-1,1)*9+find(len-1,x,t-1)+c(len-1,2)*81;
	}
	if(t==3){
		if(x[len-1]==0) return find(len-1,x,t);
		else return (x[len-1]-1)*c(len-1,2)*81+find(len-1,x,t-1)+c(len-1,3)*729;
	}
}
int main()
{
	scanf("%s",s);
	scanf("%d",&k);
	l=strlen(s);
	for(int i=0,j=l-1;j>=0;++i,--j) a[i]=s[j]-'0';
	if(k>l)printf("0");
	else{
		ans=find(l,a,k);
		printf("%d\n",ans);
	}
}
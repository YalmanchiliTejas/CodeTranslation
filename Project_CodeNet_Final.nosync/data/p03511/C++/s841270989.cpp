#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,j,k,sz,n0,n1;
char s[500010],t[500010],a[500010],b[500010];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	n0=strlen(s+1);n1=strlen(t+1);
	for(i=n/n0;i>=0;i--)if((n-n0*i)%n1==0){
		for(j=1;j<=i;j++){
			for(k=1;k<=n0;k++)a[++sz]=s[k];
		}
		for(j=1;j<=(n-n0*i)/n1;j++){
			for(k=1;k<=n1;k++)a[++sz]=t[k];
		}
		break;
	}
	sz=0;
	for(i=n/n1;i>=0;i--)if((n-n1*i)%n0==0){
		for(j=1;j<=i;j++){
			for(k=1;k<=n1;k++)b[++sz]=t[k];
		}
		for(j=1;j<=(n-n1*i)/n0;j++){
			for(k=1;k<=n0;k++)b[++sz]=s[k];
		}
		break;
	}
	for(i=1;i<=n;i++)if(a[i]<b[i]){
		for(i=1;i<=n;i++)printf("%c",a[i]);return 0;
	}
	 else if(a[i]>b[i]){
	 	for(i=1;i<=n;i++)printf("%c",b[i]);return 0;
	 }
	 for(i=1;i<=n;i++)printf("%c",a[i]);
}
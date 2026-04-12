#include<bits/stdc++.h>                          
using namespace std;    
int h,w,a[101],b[101];
char s[105][105];
int main(){
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=h;i++)
	{
		int x=0;
		for(int j=1;j<=w;j++) 
		    if(s[i][j]=='.') x++;
		if(x==w) a[i]=1;
	}
	for(int i=1;i<=w;i++)
	{
		int x=0;
		for(int j=1;j<=h;j++)
		    if(s[j][i]=='.') x++;
	    if(x==h) b[i]=1;
	}
	for(int i=1;i<=h;i++)
	{
		int flag=0;
		for(int j=1;j<=w;j++){
			if(a[i]||b[j]) continue;
			flag=1;
			printf("%c",s[i][j]);
		}
		if(flag) printf("\n");
	}
	return 0;
}
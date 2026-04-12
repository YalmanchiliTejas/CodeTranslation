#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int main(){
	int a,b,ans=0,h[111]={0},l[111]={0};
	char s[111][111];
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			cin>>s[i][j];
		}
		}
	for(int i=1;i<=a;i++){
		int sum=0;
		for(int j=1;j<=b;j++){
			if(s[i][j]=='.')sum++;
		}
		if(sum==b)h[i]=1;
	}
	for(int i=1;i<=b;i++){
		int sum=0;
		for(int j=1;j<=a;j++){
			if(s[j][i]=='.')sum++;
		}
		if(sum==a)l[i]=1;
	}
	for(int i=1;i<=a;i++){
		if(h[i]!=1){
		for(int j=1;j<=b;j++){
			if(l[j]==0)
				printf("%c",s[i][j]);
		}
		printf("\n");
		}
	}
}

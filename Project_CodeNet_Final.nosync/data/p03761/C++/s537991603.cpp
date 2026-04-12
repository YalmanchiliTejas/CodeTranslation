#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int c[55][30];
	while(~scanf("%d",&n)){
		memset(c,0,sizeof(c));
		for(int i=0; i<n; i++){
			char s[55]; int len;
			scanf("%s",s);
			len=strlen(s);
			for(int j=0; j<len; j++){
				c[i][s[j]-'a']++;
			}
		}
		char ans[55];
		int num=0;
		for(int i=0; i<26; i++){
			int mi=100000;
			for(int j=0; j<n; j++){
				mi=min(c[j][i],mi);
			}
			char c='a'+i;
			for(int i=0; i<mi; i++){
				ans[num++]=c;
			}
		}
		ans[num]='\0';
		printf("%s\n",ans);
	}
	return 0;
}
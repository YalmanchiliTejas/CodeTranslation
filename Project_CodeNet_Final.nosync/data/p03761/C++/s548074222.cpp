#include<iostream>
#include<cstdio>
#include<ctype.h>
using namespace std;
#include<cstring>
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
string s;
int cnt[27],mi[27];
int main(){
	memset(mi,0x3f,sizeof mi);
	int n=read();
	for(int i=1;i<=n;++i){
		memset(cnt,0,sizeof cnt);
		cin>>s;
		for(int j=0;j<s.length();++j)cnt[s[j]-'a']++;
		for(int j=0;j<26;j++)mi[j]=min(mi[j],cnt[j]);
	}
	for(int i=0;i<26;++i)for(int j=1;j<=mi[i];++j)putchar(i+'a');
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ran 222222
int n,ls,lt;
char s[ran],t[ran];
char ss[ran*2],tt[ran*2];
bool d[ran];
bool cmp(char*s,char*t){
	bool rev = false;
	int ls1 = ls, lt1 = lt;
	if(ls > lt){swap(s,t);swap(ls1,lt1);rev=true;}
	int ls2 = ls1, lt2 = lt1;
	while(ls2 <= n){
		memcpy(s+ls2,s,sizeof(char)*ls1);
		ls2 += ls1;
	}
	while(lt2 <= n){
		memcpy(t+lt2,s,sizeof(char)*ls1);
		lt2 += ls1;
	}
	for(int i=0; i<n; i++)
		if(s[i] != t[i])
			return !rev ? s[i] < t[i] : s[i] > t[i];
	return !rev;
}
int main(){
	scanf("%d%s%s",&n,s,t);
	ls = strlen(s), lt = strlen(t);
	memcpy(ss,s,sizeof(s));
	memcpy(tt,t,sizeof(t));
	bool ff = cmp(ss,tt);
	d[0] = true;
	for(int i=0; i<n; i++)if(d[i]){
		if(i+ls <= n)d[i+ls] = true;
		if(i+lt <= n)d[i+lt] = true;
	}
	int cur = 0;
	while(cur < n){
		bool ff1 = cur + ls <= n && d[n-cur-ls];
		bool ff2 = cur + lt <= n && d[n-cur-lt];
		if(ff1 && (ff || !ff2)){
			printf("%s",s);
			cur += ls;
		}else{
			printf("%s",t);
			cur += lt;
		}
	}
	puts("");
	return 0;
}

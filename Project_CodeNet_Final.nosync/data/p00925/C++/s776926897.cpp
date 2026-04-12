#include<stdio.h>
#include<algorithm>
using namespace std;
char str[20];
int cur;
long long num(){
	long long ret=0;
	while('0'<=str[cur]&&str[cur]<='9'){
	//	printf("%d\n",cur);
		ret*=10;
		ret+=str[cur]-'0';
		cur++;
	}
	return ret;
}
long long mul(){
	long long ret=num();
	while(str[cur]=='*'){
		cur++;
		ret*=num();
	}
	return ret;
}
long long plus(){
	long long ret=mul();
	while(str[cur]=='+'){
		cur++;
		ret+=mul();
	}
	return ret;
}
int main(){
	scanf("%s",str);
	long long a;scanf("%lld",&a);
	long long M=plus();
	long long L=0;
	cur=0;
	long long tmp=0;
	int last=0;
	while(str[cur]){
		tmp=0;
		while('0'<=str[cur]&&str[cur]<='9'){
			tmp*=10;
			tmp+=str[cur]-'0';
			cur++;
		}//printf("%lld\n",L);
		
		if(last)L*=tmp;
		else L+=tmp;
		if(!str[cur])break;
		if(str[cur]=='*')last=1;
		else last=0;
		cur++;
	}
	if(a==M&&a==L)printf("U\n");
	if(a==M&&a!=L)printf("M\n");
	if(a!=M&&a!=L)printf("I\n");
	if(a!=M&&a==L)printf("L\n");
}
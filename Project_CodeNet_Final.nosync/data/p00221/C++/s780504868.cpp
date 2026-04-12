#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cstdlib>
#define for(i,a,b) for(i=a;i<b;i++)
using namespace std;
int main(void)
{
	int m,n,now,i,j,k,ff,suu,res;
	char say[21];
	int pflg[1001];
	while(cin>>m>>n&&m&&n) {
		for(i,0,1000) pflg[i]=0;
		now=0;
		res=m;
		for(i,0,n) {
			cin>>say;
			if(res==1) continue;
			if((i+1)%15==0){
				if(strcmp(say,"FizzBuzz")!=0) pflg[now]=1,res--;
			}
			else if((i+1)%3==0) {
				if(strcmp(say,"Fizz")!=0) pflg[now]=1,res--;
			}
			else if((i+1)%5==0) {
				if(strcmp(say,"Buzz")!=0) pflg[now]=1,res--;
			}
			else if((i+1)!=atoi(say)) pflg[now]=1,res--;
			now++;now=now%m;
			if(pflg[now]==1) {
				while(1) {
					now++;now=now%m;
					if(pflg[now]==0) break;
				}
			}
		}
		now=0;
		while(pflg[now])now++;
		cout<<now+1;
		for(i,now+1,m) {
			if(pflg[i]==0)cout<<" "<<i+1;
		}
		cout<<endl;
	}
	return 0;
}
			
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	while(true){
	int to=1,so=2,ea=3,no=5,we=4,be=6;
	int n;string s;int ans=1;
	scanf("%d",&n);
	if(n==0)return 0;
	for(int i=0;i<n;i++){
		cin >> s;
		if(s=="North"){
			int to1=so;int so1=be;int be1=no;int no1=to;
			to=to1,so=so1,be=be1,no=no1;
		}
		if(s=="East"){
			int to1=we;int we1=be;int be1=ea;int ea1=to;
			to=to1,we=we1,be=be1,ea=ea1;
		}
		if(s=="West"){
			int to1=ea;int ea1=be;int be1=we;int we1=to;
			to=to1,ea=ea1,be=be1,we=we1;
		}
		if(s=="South"){
			int to1=no;int no1=be;int be1=so;int so1=to;
			to=to1,no=no1,be=be1,so=so1;
		}
		if(s=="Right"){
			int so1=ea;int ea1=no;int no1=we;int we1=so;
			so=so1,ea=ea1,no=no1,we=we1;
		}
		if(s=="Left"){
			int so1=we;int ea1=so;int no1=ea;int we1=no;
			so=so1,ea=ea1,no=no1,we=we1;
		}
		ans+=to;
	}
	printf("%d\n",ans);
	}
}
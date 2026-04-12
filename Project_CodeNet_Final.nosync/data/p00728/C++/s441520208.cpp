#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,s[1001];

int main(void){
	
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(int i=0;i<n;i++)scanf("%d",&s[i]);
		sort(s,s+n);
		int res=0;
		for(int i=1;i<n-1;i++)res+=s[i];
		printf("%d\n",res/(n-2));
	}
	
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int n,t,e;
int a[101];
int main(void){
	scanf("%d%d%d",&n,&t,&e);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int i=1;
	for(i=1;i<=n;i++){
		for(int j=1;j*a[i]<=14400;j++){
			if(j*a[i]>=t-e && j*a[i]<=t+e){
				printf("%d\n",i);
				return 0;
			}
		}
		if(i==n)printf("-1\n");
	}
    return 0;
}
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int x=800*n,s=n/15;
	int y=s*200;
	printf("%d\n",x-y);
	return 0;
}

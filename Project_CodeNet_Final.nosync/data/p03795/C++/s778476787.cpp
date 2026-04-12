#include<iostream>
#include<cstdio>
using namespace std;
int n,x;
int main(){
    scanf("%d",&n);
    x=n*800;
    for(int i=1;i<=n/15;i++)
    x-=200;
	printf("%d\n",x);
    return 0;
}
#include<cstdio>
using namespace std;
long long n,m,k,l,i=0;
int main(){
	scanf("%lld%lld%lld",&n,&m,&k),l=k;
	do l+=m+k,i++;while(l<n);
	if(l>n) i--;
	printf("%lld\n",i);
}
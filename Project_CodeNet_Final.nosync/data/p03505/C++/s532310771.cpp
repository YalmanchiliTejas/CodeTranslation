#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a<=b){
		printf("1\n");
		return 0;
	}
	if(b<=c){
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",(long long)(2*((a-b)/(b-c)+(bool)((a-b)%(b-c)))+1));
	return 0;
	
}
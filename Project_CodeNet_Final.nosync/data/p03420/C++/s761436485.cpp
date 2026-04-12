#include<cstdio>
#include<iostream>
#define ll long long 
using namespace std;
int n,k,b;
ll ans;
int main(){
	 scanf("%d%d",&n,&k);
	 if(k==0){
	 	printf("%lld\n",(ll)n*n);
	 	return 0;
	 }
	 for(b=1;b<=n;b++){
	// 	int num=max(0,(ll)(b-1-k+1)*((n+1)/b))+max(0,n-(n+1)/b*b-k+1);
	 	ans+=max(0ll,(ll)(b-1-k+1)*((n+1)/b));
	 	ans+=max(0ll,(ll)n-(ll)(n+1)/b*b-k+1);
	 //	printf("%d %d\n",b,num);
	 }
	 printf("%lld\n",ans);
}
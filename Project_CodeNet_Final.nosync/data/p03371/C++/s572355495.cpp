#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
int a,b,c,x,y;
LL sum;
int main(){
	sum=0;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	int h=min(x,y);
	if(h*a+h*b>h*2*c){
		if(x>=h&&y<=h){
			sum+=h*2*c;
			if((x-h)*a>=2*(x-h)*c) sum+=2*(x-h)*c;
			else sum+=(x-h)*a;
			printf("%lld\n",sum);
		}
		else{
			sum+=h*2*c;
			if((y-h)*b>=2*(y-h)*c) sum+=2*(y-h)*c;
			else sum+=(y-h)*b;
			printf("%lld\n",sum);
		}
	}
	else{
		sum+=h*a+h*b;
		if(x>=h&&y<=h){
			if((x-h)*a>=2*(x-h)*c) sum+=2*(x-h)*c;
			else sum+=(x-h)*a;
			printf("%lld\n",sum);
		}
		else{
			if((y-h)*b>=2*(y-h)*c) sum+=2*(y-h)*c;
			else sum+=(y-h)*b;
			printf("%lld\n",sum);
		}
	}
}
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(){
	long long int x,y,z,a;
	scanf("%lld%lld%lld",&x,&y,&z);
	a=(x-z)/(y+z);
	printf("%lld\n",a);
	return 0;
}
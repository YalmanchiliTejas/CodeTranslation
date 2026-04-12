#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	long long int x, y, z;
	scanf("%lld %lld %lld", &x, &y, &z);
	printf("%lld\n", (x - z) / (y + z));
	}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int minn(int a, int b){
	if(a < b)
		return a;
	return b;
}

int maxx(int a, int b){
	if(a > b)
		return a;
	return b;
}

int main(){
	int a, b, c, x, y;
	long long ans = 0;
	scanf("%d %d %d %d %d",&a, &b, &c, &x, &y);
	int maxy = maxx(x, y);
	int miny = minn(x, y);
	int chaxy = maxy - miny;
	if(2 * c < a + b){
		ans += miny * 2 * c;
		if(miny == x)
			ans += chaxy * b;
		else 
			ans += chaxy * a;
	}
	else{
		ans = x * a + y * b;
	}
	long long sum = 2 * c * maxy;
	if(sum < ans)
		printf("%lld\n",sum);
	else
		printf("%lld\n",ans);
return 0;
}
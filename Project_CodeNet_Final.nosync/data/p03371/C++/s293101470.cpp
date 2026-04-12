#include<bits/stdc++.h>

int main(){
	int a, b, ab, x, y;
	scanf("%d %d %d %d %d", &a, &b, &ab, &x, &y);
	ab *= 2;
	int ans = x*a+y*b;
	if(x>y) ans = std::min({ans, x*ab, (x-y)*a+y*ab});
	else ans = std::min({ans, y*ab, (y-x)*b+x*ab});
	printf("%d\n", ans);
	return 0;
}

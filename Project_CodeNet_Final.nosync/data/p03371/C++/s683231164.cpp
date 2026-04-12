#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, x, y;
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	int flag = (2*c < a + b);
	if(flag){
		int sum = 0;
		if(x < y){
			sum += 2 * c * x;
			if(2*c < b){
				printf("%d\n", sum + (y - x) * 2 * c);
			}
			else{
				printf("%d\n", sum + (y - x) * b);
			}
		}
		else{
			sum += 2*c *y;
			if(2*c < a){
				printf("%d\n", sum + (x - y) * 2 * c);
			}
			else{
				printf("%d\n", sum + (x - y) * a);
			}
		}
	}
	else{
		printf("%lld\n",1ll* x * a +1ll* y * b);
	}
}

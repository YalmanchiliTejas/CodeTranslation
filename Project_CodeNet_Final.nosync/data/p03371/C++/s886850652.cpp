#include <cstdio>
#define ll long long int

int main(void){
		int a, b, c, x, y;
		ll price = 0;
		scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
		if(a + b < c * 2){
				printf("%lld\n", (ll)(a * x + b * y));
		}else{
				int upper = x > y ? a : b;
				int max = x > y ? x : y;
				int max2 = x > y ? y : x;
				if(upper > c * 2){
						price = c * 2 * max;
						
				}else{
						price = max2 * c * 2 + upper * (max - max2);
				}
				printf("%lld\n", price);
		}
		return 0;
}

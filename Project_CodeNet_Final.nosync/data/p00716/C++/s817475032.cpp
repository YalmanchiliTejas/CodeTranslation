#include <stdio.h>
#define max(a,b) a > b ? a : b

int main(void){
	int m, money, age, n, i, j, k, sw, sub, mx;
	double rate, tmp;
	scanf("%d",&m);
	for(i = 0;i < m;i++){
		scanf("%d%d%d",&money,&age,&n);
		mx = 0x80000000;
		for(j = 0;j < n;j++){
			scanf("%d%lf%d",&sw,&rate,&sub);
			tmp = money;
			if(sw){
				for(k = 0;k < age;k++){
					tmp *= (1 + rate);
					tmp = (int)tmp;
					tmp -= sub;
				}
			}else{
				int sum = 0;
				for(k = 0;k < age;k++){
					sum += tmp * rate;
					tmp -= sub;
				}
				tmp += sum;
			}
			mx = max(mx,(int)tmp);
		}
		printf("%d\n",mx);
	}
	return 0;
}
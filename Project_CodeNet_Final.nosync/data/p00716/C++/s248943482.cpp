#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

void func(){
	int num_of_year,N,type;
	double base_money,rate,maximum = -1,interest,calc,fee;

	scanf("%lf",&base_money);
	scanf("%d",&num_of_year);
	scanf("%d",&N);

	for(int loop = 0; loop < N; loop++){
		scanf("%d %lf %lf",&type,&rate,&fee);

		if(type == 1){
			calc = base_money;

			for(int i = 0; i < num_of_year;i++){
				calc += floor(calc*rate);
				calc -= fee;
			}
			maximum = max(maximum,calc);
		}else{
			calc = base_money;
			interest = 0;

			for(int i = 0; i < num_of_year; i++){
				interest += floor(calc*rate);
				calc -= fee;
			}
			calc += interest;
			maximum = max(maximum,calc);
		}
	}
	printf("%.0lf\n",maximum);
}



int main(){

	int m;

	scanf("%d",&m);

	for(int i = 0; i < m; i++)func();

	return 0;
}
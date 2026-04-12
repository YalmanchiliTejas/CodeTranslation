#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int A,B,C,X,Y;

	scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);

	int ans = BIG_NUM;

	//Cを買う枚数を全探索
	for(int i = 0; i <= 2*(X+Y); i++){

		int num_a = i/2;
		int num_b = i/2;

		int rest_a = max(0,X-num_a);
		int rest_b = max(0,Y-num_b);

		ans = min(ans,rest_a*A+rest_b*B+C*i);
	}

	printf("%d\n",ans);

	return 0;
}

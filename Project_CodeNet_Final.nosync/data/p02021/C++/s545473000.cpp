#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int main(){

	int N;

	scanf("%d",&N);

	int tmp,sum = 0,ans = BIG_NUM;

	for(int day = 1; day <= N; day++){

		scanf("%d",&tmp);
		sum += tmp;

		ans = min(ans,sum/day);
	}

	printf("%d\n",ans);

	return 0;
}


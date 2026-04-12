#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int main(){

	int X,Y,Z;

	scanf("%d %d %d",&X,&Y,&Z);

	int ans = 0;

	for(int k = 1; k <= 100000; k++){

		if(k*Y+(k+1)*Z <= X){

			ans = k;
		}else{
			break;
		}
	}

	printf("%d\n",ans);

	return 0;
}

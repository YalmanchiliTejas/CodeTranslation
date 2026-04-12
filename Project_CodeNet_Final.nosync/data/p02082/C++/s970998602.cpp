#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll s,t;
ll p,q,M,y;


int main(){

	scanf("%lld %lld",&s,&t);

	scanf("%lld %lld %lld %lld",&p,&q,&M,&y);

	ll ans = y;
	ll a = 0;

	ans ^= a;

	for(int i = 2; i <= 100000000; i++){

		a = (a*p+q)%M;
		ans ^= a;
	}

	printf("%lld\n",ans);


	return 0;
}


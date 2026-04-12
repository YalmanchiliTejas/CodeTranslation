#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll a,b,x;

int main(){

	scanf("%lld %lld %lld",&a,&b,&x);

	ll ans = x%MOD;
	ll mult = max(0LL,(x-b)/(a-b));
	b %= MOD;
	mult %= MOD;

	printf("%lld\n",(ans+b*mult)%MOD);

	return 0;
}


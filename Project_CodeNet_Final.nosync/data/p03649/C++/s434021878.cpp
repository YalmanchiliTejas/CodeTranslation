#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define x first
#define y second

const int N = 1e6 + 10;
const int M = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> PII;

priority_queue<ll> q;

int main ()
{
	ll n;
	while(scanf("%lld", &n) != EOF){
		ll t = n, x;
		for(int i = 0; i < n; i++){
			scanf("%lld", &x);
		//	printf("%lld\n", x);
			q.push(x);
		}
		
		ll cnt = 0, T = 50;
		while(true){
			ll u = q.top(); q.pop();
			if(u < t) break;
			ll k = (u-t)/n + 1;
		//	printf("u = %lld t = %lld k = %lld\n", u, t, k);
			cnt += k;
			t -= k;
			q.push(u-k*n-k);
		}
		
		printf("%lld\n", cnt);
	}
	
	return 0;
}

/*
1234567891011
1234567894848
*/
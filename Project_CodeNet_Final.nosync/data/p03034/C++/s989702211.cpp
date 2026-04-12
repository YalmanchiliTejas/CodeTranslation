#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

ll N;
ll S[SIZE];
set<ll> SET;

int main(){

	scanf("%lld",&N);
	for(ll i = 0; i < N; i++){

		scanf("%lld",&S[i]);
	}

	ll ans = 0;
	ll L,R;

	for(ll diff = 1; diff <= N-2; diff++){

		ll tmp = 0;
		SET.clear();

		L = 0,R = N-1;
		SET.insert(L);
		SET.insert(R);

		while(true){

			L += diff;
			R -= diff;
			if(R <= diff)break;

			if(L <= N-1 && SET.count(L)){
				break;
			}
			if(L == R)break;
			if(SET.count(R)){
				break;
			}
			if(L <= N-1){
				SET.insert(L);
				tmp += S[L];
			}
			SET.insert(R);
			tmp += S[R];
			ans = max(ans,tmp);
		}
	}

	printf("%lld\n",ans);

	return 0;
}

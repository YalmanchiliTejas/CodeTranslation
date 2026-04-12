#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N;
vector<ll> A;

int main()
{
	scanf("%d",&N);
	A.assign(N,0ll);
	FOR(i,0,N){
		scanf("%lld",&A [i]);
	}
	ll sumAll = accumulate(A.begin(),A.end(),0ll);
	FOR(i,0,N) A [i] %= (N + 1);
	sort(A.begin(),A.end());
	
	for(ll i = min(sumAll,ll(N - 1) * N);i >= 0;i--){
		FOR(j,0,N + 1){
			ll sum = 0;
			bool ok = true;
			FOR(k,0,N){
				(++A [k]) %= (N + 1);
				ok &= A [k] < N;
				sum += A [k];
			}
			ok &= sum == i;
			if(ok){
				printf("%lld\n",sumAll - i);
				return 0;
			}
		}
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

ll N;
vector<ll> A;
ll allMax,allMin;
const ll INF = 2e18;

ll f(double m,ll& mx,ll& mn)
{
	double res = 0.0;
	mx = -INF;
	mn = INF;
	FOR(i,0,N){
		if(allMin == i){
			chmax(mx,A [i + N]);
			chmin(mn,A [i + N]);
			chmax(res,abs(A [i + N] - m));
			continue;
		}
		if(allMin == i + N){
			chmax(mx,A [i]);
			chmin(mn,A [i]);
			chmax(res,abs(A [i] - m));
			continue;
		}
		if(allMax == i){
			chmax(mx,A [i + N]);
			chmin(mn,A [i + N]);
			chmax(res,abs(A [i + N] - m));
			continue;
		}
		if(allMax == i + N){
			chmax(mx,A [i]);
			chmin(mn,A [i]);
			chmax(res,abs(A [i] - m));
			continue;
		}
		if(abs(A [i] - m) <= abs(A [i + N] - m)){
			chmax(mx,A [i]);
			chmin(mn,A [i]);
			chmax(res,abs(A [i] - m));
		}
		else{
			chmax(mx,A [i + N]);
			chmin(mn,A [i + N]);
			chmax(res,abs(A [i + N] - m));
		}
	}
	return res;
}

int main()
{
	scanf("%lld",&N);
	A.assign(N * 2,0);
	FOR(i,0,N){
		scanf("%lld%lld",&A [i],&A [i + N]);
	}
	allMax = max_element(A.begin(),A.end()) - A.begin();
	allMin = min_element(A.begin(),A.end()) - A.begin();
	bool flag = false;
	FOR(i,0,N){
		if(A [i] == A [allMax] && A [i + N] != A [allMin]){
			flag = true;
			break;
		}
		if(A [i + N] == A [allMax] && A [i] != A [allMin]){
			flag = true;
			break;
		}
		if(A [i] == A [allMin] && A [i + N] != A [allMax]){
			flag = true;
			break;
		}
		if(A [i + N] == A [allMin] && A [i] != A [allMax]){
			flag = true;
		}
	}

	ll ans = INF;
	if(flag){
		ll rMax = A [allMax],rMin = A [allMin];
		double lo = 0.0,hi = 1e18,mid1,mid2;
		ll l,r;
		FOR(i,0,200){
			mid1 = (lo + lo + hi) / 3;
			mid2 = (lo + hi + hi) / 3;
			if(f(mid1,r,l) <= f(mid2,r,l)){
				hi = mid2;
			}
			else{
				lo = mid1;
			}
		}
		f((lo + hi) / 2,r,l);
		chmin(ans,(rMax - rMin) * (r - l));
	}
	{
		ll rMax = A [allMax],rMin = INF;
		ll bMax = -INF,bMin = A [allMin];
		FOR(i,0,N){
			if(A [i] >= A [i + N]){
				chmax(rMax,A [i]);
				chmin(rMin,A [i]);
				chmax(bMax,A [i + N]);
				chmin(bMin,A [i + N]);
			}
			else{
				chmax(rMax,A [i + N]);
				chmin(rMin,A [i + N]);
				chmax(bMax,A [i]);
				chmin(bMin,A [i]);
			}
		}
		chmin(ans,(rMax - rMin) * (bMax - bMin));
	}

	printf("%lld\n",ans);

	return 0;
}

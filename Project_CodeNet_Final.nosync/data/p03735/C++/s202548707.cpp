#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N;
const ll INF = 2e18;

int main()
{
	scanf("%d",&N);
	vector<ll> A(N * 2);
	FOR(i,0,N){
		scanf("%lld%lld",&A [i],&A [i + N]);
	}
	int allMin = min_element(A.begin(),A.end()) - A.begin();
	int allMax = max_element(A.begin(),A.end()) - A.begin();

	ll ans = INF;
	if(abs(allMin - allMax) != N){
		map<ll,ll> mp;
		vector< pair<ll,int> > B;
		FOR(i,0,N){
			if(i == allMin){
				mp [A [i + N]]++;
				B.push_back(make_pair(A [i + N],i + N));
				continue;
			}
			if(i + N == allMin){
				mp [A [i]]++;
				B.push_back(make_pair(A [i],i));
				continue;
			}
			if(i == allMax){
				mp [A [i + N]]++;
				B.push_back(make_pair(A [i + N],i + N));
				continue;
			}
			if(i + N == allMax){
				mp [A [i]]++;
				B.push_back(make_pair(A [i],i));
				continue;
			}
			if(A [i] <= A [i + N]){
				mp [A [i]]++;
				B.push_back(make_pair(A [i],i));
			}
			else{
				mp [A [i + N]]++;
				B.push_back(make_pair(A [i + N],i + N));
			}
		}
		sort(B.begin(),B.end());
		ll res = (--mp.end())->first - mp.begin()->first;
		FOR(i,0,N){
			if(--mp [B [i].first] == 0){
				mp.erase(B [i].first);
			}
			if(B [i].second < N){
				mp [A [B [i].second + N]]++;
			}
			else{
				mp [A [B [i].second - N]]++;
			}
			chmin(res,(--mp.end())->first - mp.begin()->first);
		}
		chmin(ans,res * (A [allMax] - A [allMin]));
	}
	{
		ll rMax = -INF,rMin = INF;
		ll bMax = -INF,bMin = INF;
		FOR(i,0,N){
			if(A [i] <= A [i + N]){
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

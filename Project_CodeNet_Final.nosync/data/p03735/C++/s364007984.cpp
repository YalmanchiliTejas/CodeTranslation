#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;

int N;
int inf = 1e9+7;
int main(){
	cin >> N;
	vector<ll> X(N),Y(N);
	vector<P> S(N),L(N);
	for(int i=0;i<N;i++){
		cin >> X[i] >> Y[i];
		if(X[i]>Y[i]) swap(X[i],Y[i]);
		S[i] = {X[i],i};
		L[i] = {Y[i],i};
	}
	sort(S.begin(),S.end());
	sort(L.begin(),L.end());
	ll ans = (S[N-1].first-S[0].first)*(L[N-1].first-L[0].first);
	set<P> T;
	for(int i=0;i<=N-1;i++) T.insert({L[i].first,(i==0? inf:L[i].second)});
	ll mind = inf;
	while(1){
		ll d = T.rbegin()->first - T.begin()->first;
		mind =  min(mind,d);
		auto a = *T.rbegin();
		T.erase(*T.rbegin());
		if(a.second>=inf) break;
		T.insert({X[a.second],inf});
	}
	ans = min(ans,(L[N-1].first-S[0].first)*mind);
	cout << ans << endl;
}
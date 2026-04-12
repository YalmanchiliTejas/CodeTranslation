#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;

int N;
ll x,y;
int inf = 1e9+7;
int main(){
	cin >> N;
	vector<P> X(N),Y(N),S(N),L(N);
	for(int i=0;i<N;i++){
		cin >> x >> y;
		if(x>y) swap(x,y);
		X[i] = {x,i};
		Y[i] = {y,i};
		S[i] = {x,i};
		L[i] = {y,i};
	}
	sort(S.begin(),S.end());
	sort(L.begin(),L.end());
	ll ans = (S[N-1].first-S[0].first)*(L[N-1].first-L[0].first);
	set<P> T;
	T.insert({L[0].first,inf});
	for(int i=1;i<=N-1;i++) T.insert({L[i].first,L[i].second});
	ll mind = inf;
	while(1){
		ll d = T.rbegin()->first - T.begin()->first;
		mind =  min(mind,d);
		auto a = *T.rbegin();
		T.erase(*T.rbegin());
		if(a.second>=inf) break;
		T.insert({X[a.second].first,inf});
	}
	ans = min(ans,(L[N-1].first-S[0].first)*mind);
	cout << ans << endl;
}
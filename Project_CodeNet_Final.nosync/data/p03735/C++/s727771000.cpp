#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	int N; cin >> N;
	vector<pair<LL,LL>> P;
	LL miny = 1e12, maxy = -1;
	repp(i,0,N){
		LL x,y; cin >> x >> y;
		if(x > y) swap(x,y);
		miny = min(miny,y);
		maxy = max(maxy,y);
		P.push_back(make_pair(x,y));
	}
	sort(P.begin(),P.end());
	LL ans = (P[N-1].first-P[0].first)*(maxy-miny);
	LL s = max(P[0].second,P[N-1].first), t = P[0].second;
	repp(i,1,N){
		ans = min(ans,(maxy-P[0].first)*(s-min(t,P[i].first)));
		s = max(s,P[i].second);
		t = min(t,P[i].second);
	}
	cout << ans << endl;
	return 0;
}

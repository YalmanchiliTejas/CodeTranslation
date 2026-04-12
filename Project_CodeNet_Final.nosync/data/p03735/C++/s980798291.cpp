#include <bits/stdc++.h>

template <class T>
bool Reduce(T &a,T const &b) {
	return a>b?a=b,1:0;
}

const int XN=2e5+11;

int main() {
	//freopen("input","r",stdin);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	int n;std::cin>>n;
	static std::pair<int,int> p[XN*2];
	for(int i=1;i<=n;++i) {
		int x,y;std::cin>>x>>y;
		p[i]=std::make_pair(x,i);
		p[i+n]=std::make_pair(y,i);
	}
	std::sort(p+1,p+1+2*n);
	std::set<std::pair<int,int>> S1,S2;
	static int pre[XN];
	long long Ans=3e18;
	for(int i=1;i<=2*n;++i) {
		if(pre[p[i].second]) {
			S1.erase({pre[p[i].second],p[i].second});
			S2.insert({pre[p[i].second],p[i].second});
			S1.insert(p[i]);
		} else {
			S1.insert({pre[p[i].second]=p[i].first,p[i].second});
		}
		if(S1.size()==n)
			Reduce(Ans,1LL*(S1.rbegin()->first-S1.begin()->first)
				*((i!=2*n?p[2*n].first:S2.rbegin()->first)-(S2.empty()?p[i+1].second:S2.begin()->first)));
	}

	std::cout<<Ans<<'\n';
	return 0;
}
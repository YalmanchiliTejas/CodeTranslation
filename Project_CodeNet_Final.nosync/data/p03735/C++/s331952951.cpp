#include <bits/stdc++.h>

#define MAXN (200010)
#define ll long long

int n;
std::pair<int, int> vec[MAXN];
std::multiset<int> setr, setb;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		scanf("%d%d", &vec[i].first, &vec[i].second);
	}
	
	for(int i = 1; i <= n; ++ i){
		if(vec[i].first > vec[i].second) std::swap(vec[i].first, vec[i].second);
		setr.insert(vec[i].first);
		setb.insert(vec[i].second);
	}
	
	std::sort(vec + 1, n + vec + 1);
	
	ll ans = 1ll * (*setr.rbegin() - *setr.begin()) * (*setb.rbegin() - *setb.begin());
	for(int i = 1; i <= n; ++ i){
		setr.erase(setr.find(vec[i].first)); setr.insert(vec[i].second);
		setb.erase(setb.find(vec[i].second)); setb.insert(vec[i].first);
		
		ans = std::min(ans, 1ll * (*setr.rbegin() - *setr.begin()) * (*setb.rbegin() - *setb.begin()));
		
		//setr.erase(setr.find(vec[i].second)); setr.insert(vec[i].first);
		//setb.erase(setb.find(vec[i].first)); setb.insert(vec[i].second);
	}
	
	printf("%lld\n", ans);
	return 0;
}
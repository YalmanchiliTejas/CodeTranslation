#include<cstdio>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<vector>

using namespace std;


#define rep(i,n) for(int i=0; i<n; i++)
#define ll long long

// flip pair
template <typename A, typename B>
pair<B, A> flip_pair(pair<A, B> src) {
	return pair<B, A> (src.second, src.first);
}

// flip map
template <typename A, typename B>
multimap<B, A> flip_map(map<A, B> src) {
	multimap<B, A> dst;
	for(auto it = src.begin(); it != src.end(); ++it) {
		auto a = flip_pair(*it);
		dst.insert(a);
	}
	return dst;
}

// get frequency mapping from vector
template <typename Tval>
multimap<int, Tval> freq(vector<Tval> src) {
	map<Tval, int> counter;
	for(auto it = src.begin(); it != src.end(); ++it) {
		auto it2 = counter.find(*it);
		if(it2 != counter.end()) counter[*it]++;
		else counter[*it] = 1;
	}
	auto dst = flip_map(counter);
	return dst;
}

int main(){
	int X;
	cin >> X;
	if (X==3 || X==5 || X==7) cout << "YES" << endl;
	else cout << "NO" << endl;
	
}


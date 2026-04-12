#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	map<int,int> mp;
	while(scanf("%d,%d", &n, &m), n || m){
		mp[n] += m;
	}

	vector<int> r;
	for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it){
		r.push_back(-it->second);
	}
	sort(r.begin(), r.end());
	r.erase(unique(r.begin(), r.end()), r.end());

	while(scanf("%d", &n) != EOF){
		printf("%d\n", upper_bound(r.begin(), r.end(), -mp[n]) - r.begin());
	}
}
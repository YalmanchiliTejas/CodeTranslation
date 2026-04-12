#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

typedef std::pair<int,int> Entrant;

bool descending_Entrant(const Entrant& e1, const Entrant& e2){
	return e1.second > e2.second;
}

int main(){
	int num, points;
	std::vector<Entrant> v;
	std::map<int,int> m;
	while(scanf("%d,%d", &num, &points), num){
		v.push_back(Entrant(num, points));
	}

	std::sort(v.begin(), v.end(), descending_Entrant);

	int rank = 1;
	for(int i=0;i<v.size();i++){
		m[v[i].first] = rank;
		if(i+1 < v.size() && v[i].second != v[i+1].second)rank++;
	}

	int n;
	while(~scanf("%d", &n)){
		printf("%d\n", m[n]);
	}
}
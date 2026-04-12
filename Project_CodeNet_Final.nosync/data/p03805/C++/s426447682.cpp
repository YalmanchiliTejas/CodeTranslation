#include <bits/stdc++.h>
using namespace std;

bool check_adjacent(const vector<vector<int> > &p, int preV, int nextV){
	for(int x: p.at(preV)) {
		if(x == nextV)
			return true;
	}
	return false;
}

int main(){
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	vector<vector<int> > p(n);
	for(int i=0; i < m; i++) {
		scanf("%d%d", &a, &b);
		p.at(a-1).push_back(b-1);
		p.at(b-1).push_back(a-1);
	}
	vector<int> v(n);
	for(int i=0; i < n; i++)
		v.at(i) = i;

	int ans = 0;
	do {
		if(v.at(0) != 0) continue;
		int preV = 0;
		for(int i=1; i < n; i++) {
			if(check_adjacent(p, preV, v.at(i))) {
				if(i == n-1) ans++;
				preV = v.at(i);
				continue;
			}else{
				break;
			}
		}
	} while(next_permutation(v.begin(), v.end()));
	printf("%d\n", ans);
}

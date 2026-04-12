#include <bits/stdc++.h>
using namespace std;
vector<long long> all(51), p(51);
void calc() {
	all[0] = 1;
	p[0] = 1;
	for(int i = 1; i < 51; i++) {
		all[i] = all[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}
}
long long dfs(long long level, long long dist) {
	if(dist == 0) {
		return 0;
	}
	else if(level == 0) {
		return 1;
	}
	else if(dist == 1) {
		return 0;
	}
	else if(dist == all[level - 1] + 2) {
		return p[level - 1] + 1;
	}
	else if(dist < all[level - 1] + 2) {
		return dfs(level - 1, dist - 1);
	}
	else {
		return p[level - 1] + 1 + dfs(level - 1, dist - all[level - 1] - 2);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	long long n, x;
	cin >> n >> x;
	calc();
	cout << dfs(n, x) << endl;
	return 0;	
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main() {
	int t, s, x;
	int teams[128] = {0}, rnk[32] = {0};
	bool point[32] = {0};
	while(scanf("%d,%d", &t, &s) && (t || s)){
		point[s] = true;
		teams[t] = s;
	}
	int c = 1;
	for(int i = 30; i >= 0; --i){
		if(point[i]){
			rnk[i] = c;
			c++;
		}
	}
	while(cin >> x){
		cout << rnk[teams[x]] << endl;
	}
	return 0;
}
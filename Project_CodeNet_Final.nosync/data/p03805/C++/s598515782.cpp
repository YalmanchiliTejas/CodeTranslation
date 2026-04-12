#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
int flg[9];
vector<int> r[9];
void func(int p){
	int f = 1;
	for(int i = 1; i <= n; i++){
		if(flg[i] != 1){
			f = 0;
			break;
		}
	}
	if(f == 1) cnt++;
	else {
		for(int i = 0; i < r[p].size(); i++){
			if(flg[r[p][i]] != 1){
				flg[r[p][i]] = 1;
				func(r[p][i]);
				flg[r[p][i]] = 0;
			}
		}
	}
}
int main(void){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		r[a].push_back(b); r[b].push_back(a);
	}
	fill(flg, flg + n + 2, 0);
	flg[1] = 1;
	cnt = 0;
	func(1);
	cout << cnt << endl;
	return 0;
}
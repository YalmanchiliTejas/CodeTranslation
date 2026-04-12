#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> gr(n, vector<int>());
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		gr.at(a).push_back(b);
		gr.at(b).push_back(a);
	}
	queue<pair<int, vector<bool>>> q;
	vector<bool> c(n, false);
	c.at(0) = true;
	q.push(make_pair(0, c));
	int ans = 0;
	while(!q.empty()){
		int n_i;
		vector<bool> n_c;
		tie(n_i, n_c) = q.front(); q.pop();
		bool flag = true;
		for(int j : gr.at(n_i)){
			if(n_c.at(j) == false){
				flag = false;
				vector<bool> nxc = n_c;
				nxc.at(j) = true;
				q.push(make_pair(j, nxc));
			}
		}
		if(flag == true){
			bool add = true;
			rep(i, n){
				if(n_c.at(i) == false){
					add = false;
					break;
				}
			}
			if(add == true) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
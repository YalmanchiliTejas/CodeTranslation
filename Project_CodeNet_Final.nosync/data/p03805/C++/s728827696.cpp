#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> g;
vector<int> it;
int n = 0;
int cou = 0;
int ans = 0;

int f(int x){
	it.at(x) = 1;
	cou++;
	if(cou == n) ans++;
	rep(i, g.at(x).size()){
		if(it.at(g.at(x).at(i)) == 0) f(g.at(x).at(i));
	}
	it.at(x) = 0;
	cou--;
	return 0;
}

int main(){
	int m;
	cin >> n >> m;
	g = vector<vector<int>>(n, vector<int>(0));
	it = vector<int>(n);
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g.at(a).push_back(b);
		g.at(b).push_back(a);
	}
	f(0);
	cout << ans << endl;
	return 0;
}
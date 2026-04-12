#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<char>> g(h, vector<char>(w));
	rep(i, h) rep(j, w) cin >> g[i][j];
	
	vector<int> eh, ew;
	for(int i = 0; i < h; ++i){
		bool erase = false;
		for(int j = 0; j < w; ++j){
			if(g[i][j] == '#'){
				erase = true;
			}
		}
		if(erase) eh.push_back(i);
	}
	
	for(int i = 0; i < w; ++i){
		bool erase = false;
		for(int j = 0; j < h; ++j){
			if(g[j][i] == '#'){
				erase = true;
			}
		}
		if(erase) ew.push_back(i);
	}
	
	for(int i = 0; i < h; ++i){
		auto rh = find(eh.begin(), eh.end(), i);
		if(rh != eh.end()){
			for(int j = 0; j < w; ++j){
				auto rw = find(ew.begin(), ew.end(), j);
				if(rw != ew.end()){
					cout << g[i][j];
				}
			}
			cout << endl;
		}
	}
	
	return 0;
}


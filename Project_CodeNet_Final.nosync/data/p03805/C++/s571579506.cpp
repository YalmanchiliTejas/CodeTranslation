#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct edge { int to; int cost; };
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-10;
const double PI = acos(-1.0);
 
const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};

int n,m;
int g[10][10];

int main() {
	cin >> n >> m;
	rep(i,m){
		int a,b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}

	vi x;
	for(int i = 2; i <= n; i++) x.push_back(i);

	int cnt = 0;
	do{
		int flag = 1;
		for(int i = 0; i < x.size(); i++){
			int y = (i == 0 ? 1 : x[i-1]);
			if(!g[y][x[i]]) flag = 0;
		}
		if(flag) cnt++;
	}while(next_permutation(all(x)));
	
	cout << cnt << endl;

	return 0;
}
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<utility>
#include<numeric>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<functional>
#include<iterator>
#include<cmath>
#include<cctype>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const ll LINF = 1e18;

struct edge{int to,cost;};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h,w;
	cin >> h >> w;

	char a[h][w];
	bool space=true;
	int hh=0;
	for(int i=0;i<h;i++){
		space=true;
		for(int j=0;j<w;j++){
			cin >> a[i-hh][j];
			if(a[i-hh][j] == '#') space=false;
		}
		if(space) hh++;
	}
	bool ww[w];
	for(int j=0;j<w;j++){
		space=true;
		for(int i=0;i<h-hh;i++){
			if(a[i][j]=='#') space=false;
		}
		if(space) ww[j] = true;
		else		ww[j] = false;
	}

	for(int i=0;i<h-hh;i++){
		for(int j=0;j<w;j++){
			if(ww[j]) continue;
			cout << a[i][j];
		}
		cout << "\n";
	}

	return 0;
}
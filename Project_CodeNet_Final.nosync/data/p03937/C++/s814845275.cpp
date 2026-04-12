#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
int main(){
	int h,w;cin>>h>>w;
	vector<vector<char>> a(h,vector<char>(w));
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin>>a[i][j];
		}
	}
	int x = 0;int y = 0;
	int cnt = 0;
	while(cnt < h * w){
		if (x + 1 < h && a[x + 1][y] == '#'){
			a[x][y] = '.';
			x++;
		}
		else if(y + 1 < w && a[x][y] == '#'){
			a[x][y] = '.';
			y++;
		}
		if (x == h - 1 && y == w - 1){
			a[x][y] = '.';
			break;
		}
		cnt ++;
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if (a[i][j] == '#'){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
	
	return 0;
}
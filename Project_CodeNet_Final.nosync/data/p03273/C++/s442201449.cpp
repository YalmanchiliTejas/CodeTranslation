#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int h,w;
	bool f1[100] = {},f2[100] = {};
	string field[100];
	cin >> h >> w;
	for(int i = 0;i < h;i++) cin >> field[i];
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(field[i][j] == '#') f1[i] = true;
		}
	}
	for(int i = 0;i < w;i++){
		for(int j = 0;j < h;j++){
			if(field[j][i] == '#') f2[i] = true;
		}
	}
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(f1[i] && f2[j]) cout << field[i][j];
		}
		if(f1[i]) cout << endl;
	}
	return 0;
}
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
	int n,s[100010],ma = 0;
	bool on[100010] = {};
	cin >> n;
	for(int i = 0;i < n;i++) cin >> s[i];
	for(int i = 1;i <= n / 2;i++){
		//cout << i << ":";
		int sum = 0;
		for(int j = 0;n - 1 - j > i;j += i){
			sum = sum + s[j] + s[n - 1 - j];
			//cout << sum << " ";
			on[j] = true;
			if(!on[n - 1 - j]) chmax(ma,sum);
			on[n - 1 - j] = true;
		}
		for(int j = 0;n - 1 - j > i;j += i){
			on[j] = false;
			on[n - 1 - j] = false;
		}
		//cout << endl;
	}
	cout << ma << endl;
}

#include <bits/stdc++.h>
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w
using namespace std;

#define int long long 
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,x[200000],y[200000],ma = 0,mi = INF,ans = INF;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x[i] >> y[i];
		if(x[i] > y[i]) swap(x[i],y[i]);
		ma = max(ma,y[i]);
		mi = min(mi,x[i]);
	}
	int maf = -1;
	for(int i = 0;i < n;i++){
		if(ma == y[i] && mi == x[i]) maf = i;
	}
	int tmi,tma;
	if(maf == -1){
		vector<P> vec;
		for(int i = 0;i < n;i++) vec.push_back(P(y[i],x[i]));
		sort(all(vec),greater<P>());
		tma = vec[0].first;
		tmi = vec[n - 1].first;
		int lim = 0;
		ans = min(ans,(ma - mi) * (tma - tmi));
		for(P p : vec){
			tma = max(lim,p.first);
			ans = min(ans,(ma - mi) * (tma - tmi));
			lim = max(lim,p.second);
			tmi = min(tmi,p.second);
		}
	}
	tmi = mi;
	tma = ma;
	for(int i = 0;i < n;i++){
		tmi = max(tmi,x[i]);
		tma = min(tma,y[i]);
	}
	cout << min(ans,(tmi - mi) * (ma - tma)) << endl;
	return 0;
}
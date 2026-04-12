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
//using ll = long long;
using P = pair<int,int>;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int sou[55] = {1};

map<P,int> memo;

int calc(int n,int x){
	if(memo.count(P(n,x))) return memo[P(n,x)];
	if(!n) return x;
	if(x <= 1) return 0;
	else if(x <= 1 + sou[n - 1]) return memo[P(n,x)] = calc(n - 1,x - 1);
	else if(x == 2 + sou[n - 1]) return memo[P(n,x)] = calc(n - 1,sou[n - 1]) + 1;
	else if(x <= 2 + sou[n - 1] * 2) return memo[P(n,x)] = calc(n - 1,sou[n - 1]) + calc(n - 1,x - 2 - sou[n - 1]) + 1;
	else return memo[P(n,x)] = calc(n - 1,sou[n - 1]) * 2 + 1;
}

signed main(){
	int n,x;
	cin >> n >> x;
	for(int i = 1;i <= n;i++) sou[i] = sou[i - 1] * 2 + 3;
	cout << calc(n,x) << endl;
}
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;
ll  LINF = 1e18;

int main(){
	ll n,m,x;cin >> n >> x >> m;
	vector<int> res(m,-1),a;
	int len = 0;
	ll tot = 0;
	while(res[x]==-1){
		a.push_back(x);
		res[x] = len;
		tot += x;
		x = (x*x)%m;
		len++;
	}
	int peri = len - res[x];
	ll s = 0;
	for(int i = res[x];i < len;i++) s += a[i];
	ll ans = 0;
	if(n<=len) rep(i,n) ans += a[i];
	else{
		ans += tot;
		n -= len;
		ans += s*(n/peri);
		n %= peri;
		rep(i,n) ans += a[res[x]+i];
	}
	cout << ans << endl;
}





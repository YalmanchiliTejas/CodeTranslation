#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;


ll p[51] = {0};
ll b[51] = {0};
ll ans = 0;

ll func(ll eat,ll level){
	if(level==0) return 1;
	if(eat<=level) return 0;
	ll res = 0;
	if(eat==(b[level]+1)/2){
		res++;
		res += func(eat-2,level-1);
	}
	else if(eat>(b[level]+1)/2){
		res++;
		res += p[level-1];
		res += func(eat-b[level-1]-2,level-1);
	}else{
		res += func(eat-1,level-1);
	}
	return res;
}

int main()
{
	ll n,x;
	cin >> n >> x;

	p[0] = 1;
	b[0] = 1;
	for(int i = 1; i <= 50; i++){
		p[i] = 2*p[i-1] + 1;
		b[i] = 2*b[i-1] + 3;
	}
	// for(int i = 0; i <= n; i++){
	// 	cout << p[i] << " " << b[i] << endl;
	// }

	ans = func(x,n);
	cout << ans << endl;

	return 0;
}
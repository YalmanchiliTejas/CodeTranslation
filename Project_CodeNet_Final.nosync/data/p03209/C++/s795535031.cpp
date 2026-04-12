#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
inline int ri() {
	int r; cin >> r; return r;
}
ll n, x;
ll sum = 0;
vector<ll>  p, num; //レベルiバーガーに含まれるパティの枚数 / 全体

void dfs(int depth, ll cur) {
	if(depth == 1){
	//	cerr << sum << endl;
		if(cur == 2)sum += 1;
		if(cur == 3)sum += 2;
		if(cur >= 4)sum += 3;
		return;
	}
	if(cur <= (num[depth] / 2)) {
		dfs(depth - 1, max(0LL, cur - 1) );
	} else {
		sum += p[depth - 1] + 1;
		dfs(depth - 1, cur - max(num[depth - 1] + 2, 0LL) );	
	}
}

int main()
{
	cin >> n >> x;
	p.resize(n + 1), num.resize(n + 1);
	p[0] = num[0] = 1;
	for(int i = 1; i < n + 1; i++) {
		p[i] = p[i - 1] * 2 + 1;
		num[i] = num[i - 1] * 2 + 3;
		//cerr << p[i] << endl;
	}
	dfs(n, x);
	cout << sum << endl;
}
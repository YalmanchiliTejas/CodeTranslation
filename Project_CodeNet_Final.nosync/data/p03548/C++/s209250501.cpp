#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999

using namespace std;

int main(){
	cin.tie(0);					//cinとcoutの結び付きを解除
	ios::sync_with_stdio(false);//stdioとの同期を解除
	
	int x,y,z,a,b;	//椅子、人幅、隙間
	
	cin >> x >> y >> z;
	
	a = x / (y + z);
	b = x % (y + z);
	if(b < z) a--;
	
	cout << a;
	
	return 0;
	
}

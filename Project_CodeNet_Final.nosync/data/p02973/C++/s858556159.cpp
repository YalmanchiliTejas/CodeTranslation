#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+2;
int N;
int a[MAX_N];

void solve()
{
	multiset<int, greater<int>> seen;
	for(int i=0;i<N;++i){
		auto it = seen.upper_bound(a[i]);
		if(it == seen.end()){
			seen.insert(a[i]);
		}else{
			seen.erase(it);
			seen.insert(a[i]);
		}
	}
	cout << seen.size() << '\n';
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i)cin >> a[i];
	solve();
	return 0;
}
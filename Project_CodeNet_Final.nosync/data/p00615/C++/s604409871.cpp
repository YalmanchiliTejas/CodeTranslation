#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;

void solve()
{
	int bef = 0, in;
	int res = 0;
	priority_queue<int, vector<int>, greater<int> > pq;

	for(int i = 0; i < n + m; i++){
		cin >> in;
		pq.push(in);
	}
	while(pq.size()){
		in = pq.top();
		pq.pop();
		res = max(res, in - bef);
		bef = in;
	}

	cout << res << endl;
}


int main(void)
{
	while(cin >> n >> m, n | m)
		solve();
	return 0;
}
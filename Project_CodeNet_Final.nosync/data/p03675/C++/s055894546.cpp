#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+10;
int a[MAX_N];
int N;
void solve()
{
	deque<int> que;
	for(int i=0;i<N;++i){
		if(i%2) que.push_front(a[i]);
		else que.push_back(a[i]);
	}
	if(N%2) reverse(que.begin(), que.end());
	for(int i=0;i<N-1;++i){
		cout << que[i]  << " ";
	}
	cout << que.back() << endl;
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i)cin >> a[i];
	solve();
	return 0;
}
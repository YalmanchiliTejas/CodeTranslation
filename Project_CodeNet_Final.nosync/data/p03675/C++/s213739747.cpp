#include<bits/stdc++.h>
using namespace std;
int n;
deque<int>que;
signed main() {
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;cin>>x;
		if(i&1)que.push_front(x);
		else que.push_back(x);
	}
	while(!que.empty())
		if(n&1)cout<<que.front()<<" ",que.pop_front();
		else cout<<que.back()<<" ",que.pop_back();
}
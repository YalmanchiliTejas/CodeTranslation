/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

int n, x;

int main(){
	scanf("%d", &n);
	deque <int> q;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		if(i & 1) q.push_back(x);
		else q.push_front(x);
	}
	vector <int> ans;
	while(!q.empty()){
		ans.push_back(q.front());
		q.pop_front();
	}
	if(n & 1) reverse(ans.begin(), ans.end());
	for(auto u : ans){
		printf("%d ", u);
	}
	printf("\n");
	return 0;
}
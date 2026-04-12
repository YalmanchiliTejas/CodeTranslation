#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;

deque<int> dq;

int main(){
	int n; scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		if(i % 2 == 1) dq.push_back(x);
		else dq.push_front(x);
	}
	if(n & 1) reverse(dq.begin(), dq.end());
	for(auto &i : dq) printf("%d ", i);
}

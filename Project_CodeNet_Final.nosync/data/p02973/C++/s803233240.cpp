#include <bits/stdc++.h>
using namespace std;
#define N 200005

multiset <int> v;
multiset <int> ::iterator it;
int main() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i=1,x; i<=n; i++) {
		scanf("%d",&x);
		it = v.lower_bound(x);
		if(it == v.begin()) ans ++,v.insert(x);
		else {
			it --;
			v.erase(it);
			v.insert(x);
		}
	}
	cout<<ans;
	return 0;
}
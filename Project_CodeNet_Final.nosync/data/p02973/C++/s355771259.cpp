#include <bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;

int main() {
	int n, a[100010];
	scanf("%d",&n);
	int c=0;
	multiset<int> st;
	for(int i=1; i<=n; i++) {
		scanf("%d",a+i);
		auto it=st.lower_bound(a[i]);
		if(it!=st.begin()) {
			it--;
			st.erase(st.find(*it));
		} else c++;
		st.insert(a[i]);
	}
	printf("%d",c);
	return 0;
}
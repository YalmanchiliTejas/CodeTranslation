#include<bits/stdc++.h>
using namespace std;
int n,i,a,t,ans;
multiset<int>s;
multiset<int>::iterator it;
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&a),it=s.lower_bound(a);
		if(it!=s.begin())it--,s.erase(it);
		else ans++;
		s.insert(a);
	}
	printf("%d\n",ans);
	return 0;
}
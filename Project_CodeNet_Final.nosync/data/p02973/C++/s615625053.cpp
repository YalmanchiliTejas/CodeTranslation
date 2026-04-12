#include<bits/stdc++.h>
#define M 100005
using namespace std;
int n;
multiset<int>Q;
multiset<int>::iterator it;
int main() {
	int ans=0;
	scanf("%d",&n);
	for(int x,i=1; i<=n; i++) {
		scanf("%d",&x);
		it=Q.upper_bound(-x);
		if(it!=Q.end())Q.erase(it);
		else ans++;
		Q.insert(-x);
	}
	printf("%d\n",ans);
	return 0;
}
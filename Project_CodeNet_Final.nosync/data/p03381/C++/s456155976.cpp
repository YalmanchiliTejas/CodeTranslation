#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
int n,i,x;
vector<PII> a;
int ans[200007];

int main() {
	scanf("%d",&n);
	for (i=0 ; i<n ; i++) {
		scanf("%d",&x);
		a.push_back(PII(x,i));
	}
	
	sort(a.begin(), a.end());
	
	
	
	for (i=0 ; i<n ; i++) {
		//printf("%d %d\n",a[i].first,a[i].second);
		if (i < n/2) ans[a[i].second] = a[n/2].first; else ans[a[i].second] = a[n/2-1].first;
	}
	
	for (i=0 ; i<n ; i++) printf("%d\n",ans[i]);
}

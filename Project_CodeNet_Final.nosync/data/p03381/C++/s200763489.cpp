#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[200010];
int pos[200010];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d",&x);	
		a[i] = make_pair(x,i);
	}
	sort(a,a+n);
	for (int i = 0; i < n; i++) pos[a[i].second] = i;
	for (int i = 0; i < n; i++) {
		if (pos[i] < n/2) printf("%d\n",a[n/2]);
		else printf("%d\n",a[n/2-1]);
	}
	
}
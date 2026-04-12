#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n;
pair<int,pair<int,int> > a[N];

bool cmp(pair<int,pair<int,int> >P1,pair<int,pair<int,int> > P2) {
	return P1.second.first<P2.second.first;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].first);
	for (int i=1;i<=n;i++) a[i].second.first=i;
	sort(a+1,a+n+1);
	int t=n/2;
	for (int i=1;i<=n;i++) {
		int x=i-1,y=n-i;
//		a[i].second.second=a[i+(y-x)/2].first;
		if (i<=t) a[i].second.second=a[t+1].first;
		else a[i].second.second=a[t].first;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) printf("%d\n",a[i].second.second);
}
#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,x,ans;
multiset<int> s;
multiset<int>::iterator it;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(x);
		it=s.lower_bound(x);
		if (i==1||it==s.begin()) s.insert(x),ans++;
		else {
			it--;
			s.erase(it);
			s.insert(x);
		}
	}
	printf("%d\n",ans);
	return 0;
}
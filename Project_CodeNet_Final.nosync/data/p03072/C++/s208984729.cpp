#include<bits/stdc++.h>
#define reg(i,a,b) for(int i=a;i<=b;++i)
#define reh(i,a,b) for(int i=b;i>=a;--i)
#define in(x) scanf("%d",&x)
#define fro freopen("D:\\testdata.in", "r", stdin)
#define il inline
using namespace std;
typedef long long ll;
const int mx=1e5+10;
ll ans;
int t;
int main(){
	int n;
	scanf("%d",&n);
	reg (i,1,n) {
	    int x;
	    in(x);
	    if (t<=x) {
	       t=max(t,x);
	       ++ans;
	    }

	}
	printf("%lld\n",ans);



	return 0;
}



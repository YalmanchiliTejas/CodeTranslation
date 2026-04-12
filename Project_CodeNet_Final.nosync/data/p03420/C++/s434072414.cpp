#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=int(l);i<int(r);i++)
#define put(x) cout<<#x<<" = "<<x<<endl;
#define X first
#define Y second
#define pb push_back
#define pp pop_back
using namespace std;
typedef long long num;
typedef pair<int,int> point;
const int maxn=1e5+10;

int n,k;
num ans;
int32_t main(){
    cin>>n>>k;
    if(k==0){
	cout<<1ll*n*n<<endl;
	return 0;
    }
    rep(b,k+1,n+1){
	int cnt=b-k;
	ans+=cnt*(n/b);
	int n0=n%b;
	if(n0==0) continue;
	ans+=max(0,n0-k+1);
    }
    cout<<ans<<endl;
}

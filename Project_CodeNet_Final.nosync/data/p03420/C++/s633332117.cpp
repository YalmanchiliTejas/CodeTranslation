#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> int_pair;
typedef pair<ll,ll> ll_pair;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
const ll inf = 1e9+7;
const ll N=100001;
ll n,k,ans=0;

int main(){
	cin>>n>>k;
	if(k==0){
		ans=n*n;
		cout<<ans<<endl;
		return 0;
	}
	FOR(i,k+1,n+1){
		ans+=(i-k)*(n/i);
		if(n-(n/i)*i>=k){
			ans+=n-(n/i)*i-k+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

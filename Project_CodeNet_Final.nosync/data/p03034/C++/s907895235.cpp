#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
	int n;
	cin>>n;
	ll a[n];
	rep(i,n)cin>>a[i];
	ll ans=0;
	REP(i,1,n-1){
		map<int,int> mp;
		ll ret=0;
		for(int j=0;j<n;j+=i){
			if(n-1-j<i)break;
			ret+=a[j];
			if(++mp[j]==2)ret=-longinf;
			ret+=a[n-1-j];
			if(++mp[n-1-j]==2)ret=-longinf;
			ans=max(ans,ret);
		}
	}
	cout<<ans<<endl;
	return 0;
}

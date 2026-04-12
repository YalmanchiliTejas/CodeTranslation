#include<ctime>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath> 
#include<cstring> 
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
#include<deque>
#include<queue>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<set>
#include<bitset>
#include<iomanip>
#include<utility>
#include<functional>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cwchar>
#include<cwctype>
#include<exception>
#include<locale>
#include<numeric>
#include<new>
#include<stdexcept>
#include<limits>
using namespace std;

#define ll long long
#define INF 1e9
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int>
#define sz(s) s.size()
#define all(s) (s.begin(),s.end())

const int maxn=55;
int n;
ll a[maxn],b[maxn];

bool check(ll cnt){
	ll cur=n-1-cnt;
	ll need=0;
//	REP(i,n)b[i]=a[i]+cnt;
	REP(i,n){
		if(a[i]>cur){
			need+=(a[i]-cur+(ll)n)/(ll)(n+1);
		}
	} 
	return need<=cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	REP(i,n)cin>>a[i];
	ll l=0,r=(ll)INF*(ll)INF;
	while(r-l>1){
		ll mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	ll ans=(ll)INF*(ll)INF;
	for(ll i=max(l-100*n,0ll);i<=min(l+100*n,(ll)INF*(ll)INF);i++)
	if(check(i))ans=min(ans,i);
	cout<<ans;
	return 0;
}
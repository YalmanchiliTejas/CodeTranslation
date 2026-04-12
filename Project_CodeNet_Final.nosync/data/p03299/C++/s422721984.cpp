#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define REP(i,n) for (int i=1;i<=n;++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define read(x) scanf("%d",&x)
const ll MOD=1e9+7;
int n;
int H[105];
inline ll pow2(int exp){
	ll ret=1,tmp=2;
	while(exp){
		if (exp&1) ret=ret*tmp%MOD;
		tmp=tmp*tmp%MOD;
		exp>>=1;
	}
	return ret;
}
inline pair<ll,ll> dp(int l,int r,int h){
	int low=2e9,cnt=0;
	for (int i=l;i<=r;++i){
		if (low==H[i]) ++cnt;
		else if (H[i]<low) low=H[i],cnt=1;
	}
	if (cnt==r-l+1){
		return mp(pow2(low-h)%MOD,(pow2(cnt)+pow2(low-h)-2)%MOD);
	}
	else{
		pair<ll,ll> data[105];int cntseg=0;
		for (int i=l;i<=r;){
			while(i<=r&&H[i]==low) ++i;
			int nl=i;
			while(i<=r&&H[i]>low) ++i;
			int nr=i-1;
			if (nr<nl) continue;
			data[++cntseg]=dp(nl,nr,low);
		}
		pair<ll,ll> ret=mp(1,1);
		for (int i=1;i<=cntseg;++i) ret.F=ret.F*data[i].F%MOD;
		ret.F=ret.F*pow2(low-h)%MOD;
		ll part1=1,part2=1;
		for (int i=1;i<=cntseg;++i) part1=part1*(data[i].F+data[i].S)%MOD;
		part1=part1*pow2(cnt)%MOD;
		for (int i=1;i<=cntseg;++i) part2=part2*data[i].F%MOD;
		part2=part2*(pow2(low-h)-2)%MOD;
		ret.S=(part1+part2)%MOD;
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i) cin>>H[i];
	pair<ll,ll> ret=dp(1,n,0);
	cout<<ret.S<<endl;
	return 0;
}
#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));
ll n,a[55];

int main(){
	cin >> n;
	REP(i,0,n) cin >> a[i];
	
	ll c=0;
	while(1){
		sort(a,a+n); reverse(a,a+n);
		if(a[0]<n) break;
		
		ll pos=a[0]/n; a[0]-=pos*n;
		REP(i,1,n) a[i]+=pos;
		c+=pos;
	}
	
	cout << c << endl;
	return 0;
}


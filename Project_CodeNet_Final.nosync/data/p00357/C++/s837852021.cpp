#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

int n,d[300000];
int r;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n;
	REP(i,n) {
		cin>>d[i];
	}
	REP(i,n) {
		if(r<i*10) {
			cout<<"no"<<endl;
			return 0;
		}
		r=max(r,i*10+d[i]);
	}
	r=(n-1)*10;
	for(int i=n-1;i>=0;i--) {
		if(r>i*10) {
			cout<<"no"<<endl;
			return 0;
		}
		r=min(r,i*10-d[i]);
	}
	cout<<"yes"<<endl;

	return 0;
}


#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<ll, int> P;

int n;
ll a[200000];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n;
	REP(i,n) cin>>a[i];

	for(int i=n-1;i>0;i-=2) cout<<a[i]<<' '<<flush;
	if(n%2==0){
		for(int i=0;i<n-1;i+=2) cout<<a[i]<<' '<<flush;
	}
	else {
		cout<<a[0]<<' '<<flush;
		for(int i=1;i<n-1;i+=2) cout<<a[i]<<' '<<flush;
	}
	cout<<endl;

	return 0;
}

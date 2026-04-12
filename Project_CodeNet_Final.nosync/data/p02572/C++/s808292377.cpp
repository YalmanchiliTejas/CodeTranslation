#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

void solve(int test_case) {
	int n;
	cin>>n;
	vector<ll> arr(n),srr(n,0);
	for(ll &i:arr)cin>>i;
	srr[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--) {
		srr[i]=(arr[i]+srr[i+1])%1000000007;
	}
	//REP(i,0,n-1)cerr<<srr[i]<<" ";
	ll sum = 0;
	REP(i,0,n-2) sum = (sum+(arr[i]*srr[i+1])%1000000007)%1000000007;
	cout<<sum;
}

int main() {
	
	////// FILE BASED IO////
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
}	

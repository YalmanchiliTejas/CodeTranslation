/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
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

#define MOD 1000000007

void solve(int test_case) {
	int n;
	cin>>n;
	vi arr(n);
	for(int &i:arr)cin>>i;
	ll sol = INT_MIN;
	for(int ii=0;ii<=1;ii++){
		if(ii)
			sort(arr.begin(),arr.end());
		else
			sort(arr.rbegin(),arr.rend());
		int l=0,r=n-1, li = (n-1)/2,ri=(n-1)/2;
		vi ans(n);
		ans[li] = arr[l++];
		li--;ri++;
		while(ri!=n) {
			ans[ri++]=arr[r--];
			if(li!=-1)ans[li--]=arr[r--];
			if(ri!=n) ans[ri++]=arr[l++];
			if(li!=-1)ans[li--]=arr[l++];
		}
		ll sum = 0;
		for(int i=1;i<n;i++)sum+=abs(ans[i]-ans[i-1]);
		sol=max(sum,sol);
	}
	cout<<sol;
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	

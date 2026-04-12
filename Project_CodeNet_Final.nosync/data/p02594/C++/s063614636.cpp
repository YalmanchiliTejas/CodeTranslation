#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define all(x) x.begin(),x.end()
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932384626
#define mod 1000000007
#define modd 998244353

void io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	io();
	
	int T=1;
	// cin>>T;
	while(T--) {
		int n;
		cin>>n;
		cout<<(n>=30 ? "Yes" : "No");

	}
	return 0;
}

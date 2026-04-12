#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(a) cerr << #a << ": " << a << endl
#define sz(a) int(a.size())
#define rep(i,n) for(int i=0;i<n;i++)
#define forr(i, st, en) for(int i = st; i <= en; i++)
#define all(v) (v).begin(),(v).end()
#define X first
#define Y second
#define pb push_back
#define fast cin.tie(0); ios::sync_with_stdio(false)
#define vi vector<int>
#define vii vector<vector<int>>

int32_t main(){ fast;
	int n; cin>>n;
	vector<int> a(n);
	vector<long long> b(n + 1, 0);
	const int mod = 1e9 + 7;
	rep(i, n){
		cin>>a[i];
		b[i + 1] = b[i] + a[i];
	}
	ll answer = 0;
	rep(i, n){
		long long sum = (b[n] - b[i + 1]) % mod;
		answer = (answer + a[i] * sum) % mod;
	}
	cout<<answer<<endl;
}

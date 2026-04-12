#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define nl '\n'
#define print(vec,l,r) for(int i = (l); i < (r); i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x) cerr << #x << " = " << (x) << endl;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pi;

const ll MOD = 1e9 + 7;

void solve()
{
	int n;
	cin>>n;
	ll a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	ll sum = 0;
	for(int i=0; i<n; i++)
		sum += a[i];
	ll sq = 0;
	for(int i=0; i<n; i++)
		sq += (a[i]*a[i])%MOD;
	sum %= MOD;
	sq %= MOD;
	ll answer = (sum*sum)%MOD - sq;
	if(answer < 0) answer += MOD;
	if(answer%2 == 1) answer += MOD;
	answer /= 2;
	cout<<answer%MOD<<nl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

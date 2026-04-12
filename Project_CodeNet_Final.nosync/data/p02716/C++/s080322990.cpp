#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 200005;
const ll inf = 1LL<<58;
map<int, ll> mem[N];
ll a[N];

ll dp(int ind, int k){
	if(k == 0)return 0;
	if(ind + 1 < 2*k)return -inf;
	if(ind == 1)return a[1];
	if(mem[ind].find(k) != mem[ind].end())return mem[ind][k];
	ll ret = dp(ind - 1, k);
	if(k == 1)ret = max(ret, a[ind]);
	if(ind > 2 && k > 1)ret = max(ret, dp(ind - 2, k - 1) + a[ind]);
	if(ind > 3 && k > 1)ret = max(ret, dp(ind - 3, k - 1) + a[ind]);
	if(ind > 4 && k > 1)ret = max(ret, dp(ind - 4, k - 1) + a[ind]);
	// cout<<ind<<" "<<k<<" "<<ret<<endl;
	return mem[ind][k] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	cout<<dp(n, n/2)<<endl;

	return 0;
}
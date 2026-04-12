#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define ppb pop_back
#define vll vector<ll>
#define vi vector<int>
#define endl "\n"

const ll INF = 1000000007;

/*
const int max_size = 100001;
int parent[max_size];
int Size[max_size];

int root(int x){
	while(x!=parent[x]){
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void sunion(int x,int y){
	int rx = root(x);
	int ry = root(y);
	if(rx != ry){
		if(Size[rx] > Size[ry]){
			parent[ry] = parent[rx];
			Size[rx] += Size[ry];
		}
		else{
			parent[rx] = parent[ry];
			Size[ry] += Size[rx];
		}
	}
}
*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc=1;
	//cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		ll a[n],pre[n+1]={0};
		for (int i=0;i<n;i++) {
			cin >> a[i];
			pre[i+1] = pre[i] + a[i];
			pre[i+1] %= INF;
		}
		ll ans = 0;
		for (int i=0;i<n-1;i++) {
			ll z = (pre[n] - pre[i+1] + INF)%INF;
			//cout << z << endl;
			z = (z * a[i])%INF;
			//cout << z << endl;
			ans = (ans + z)%INF;
		}
		cout << ans << endl;
	}
	return 0;
}

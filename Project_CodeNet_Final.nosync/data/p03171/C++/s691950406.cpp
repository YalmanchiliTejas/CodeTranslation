#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3005;
int n;
vector<ll> arr;
ll cache[N][N];

ll dp(int i, int j){
	if( i >= n or j >= n ){ return 0; }
	if( i < 0 or j < 0 ){ return 0; }
	if( i == j ){
		cache[i][j] = arr[i];
		return arr[i];
	}
	ll &ans = cache[i][j];
	if( ans != -1 ){ return ans; }
	ans = max( arr[i] - dp(i+1,j), arr[j] - dp(i,j-1));
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	arr.resize(n);
	for(int i=0; i<n; ++i){
		cin>>arr[i];
	}
	memset(cache,-1,sizeof(cache));
	ll ans = dp(0,n-1);
	cout<<ans<<endl;

	return 0;
}

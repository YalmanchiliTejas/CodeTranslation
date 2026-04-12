#include <bits/stdc++.h>
#define ll  long long int
#define ull unsigned long long int 
#define pb  push_back
#define mp  make_pair
#define pii pair<int, int>
using namespace std;

const ll mod = 1e9+7;
const int N = 3e3;
ll arr[N+1] = {0};
bool check[N+1][N+1] = {0};
ll dp[N+1][N+1] = {0};
int first;

ll dp_recurse(int l, int r){
	if(l==r){
		if(first == 1){
			return +arr[l];
		}
		return -arr[l];
	}

	if(check[l][r] == 1){
		return dp[l][r];
	}

	if((r-l+1)%2 == first){
		dp[l][r] = max(arr[l] + dp_recurse(l+1, r), arr[r] + dp_recurse(l, r-1));
	}
	else{
		dp[l][r] = min(dp_recurse(l+1, r) - arr[l], dp_recurse(l, r-1) - arr[r]);
	}

	check[l][r] = 1;

	return dp[l][r];
}

void solve(){
    //solve here//
	int n;
	cin >> n;

	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}

	first = n%2;

	cout << dp_recurse(1, n) << endl;
}


int main(){
    ll t=1;
  //  cin >> t;
    while(t--){
        solve();
    }
}


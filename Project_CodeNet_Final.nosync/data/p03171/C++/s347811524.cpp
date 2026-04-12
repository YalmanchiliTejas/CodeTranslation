#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

int n;
bool done[3003][3003];
ll a[3003],memo[3003][3003];

ll solve(int i, int j){
	int k;
	if(done[i][j]){
		return memo[i][j];
	}
	done[i][j] = true;
	k = n-(j-i+1);
	if(k==n){
		memo[i][j] = 0ll;
		return memo[i][j];
	}
	if(k%2){
		memo[i][j] = min(solve(i+1,j)-a[i],solve(i,j-1)-a[j]);
	}else{
		memo[i][j] = max(solve(i+1,j)+a[i],solve(i,j-1)+a[j]);
	}
	return memo[i][j];
}

int main(void){
	int i;
	fill(done[0],done[3003],false);
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	cout << (solve(0,n-1)) << endl;
	return 0;
}

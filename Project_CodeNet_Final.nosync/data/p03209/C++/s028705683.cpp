#include <bits/stdc++.h>

using namespace std;

template <class T>
using lim = numeric_limits<T>;

typedef long long ll;
typedef long double ld;

const int maxN = 50;
ll burger[maxN+1];
ll patty[maxN+1];

ll solve(int n, ll x){
	if (x == 0){
		return 0;
		}
	else if (x == burger[n]){
		return patty[n];
		}
	else if (x == burger[n-1]+1){
		return patty[n-1];
		}
	else if (x == burger[n-1]+2){
		return patty[n-1]+1;
		}
	else if (x < burger[n-1]+2){
		return solve(n-1,x-1);
		}
	else{
		return patty[n-1]+1+solve(n-1, x-burger[n-1]-2);
		}
	}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll x;
	cin >> n >> x;
	
	// # of level 0 burger and patty
	burger[0] = 1;
	patty[0] = 1;
	
	// compute until level n burger
	for (int i = 1; i <= n; i++){
		burger[i] = 2*burger[i-1]+3;
		patty[i] = 2*patty[i-1]+1;
		}
	
	cout << solve(n, x) << endl;
	}
	

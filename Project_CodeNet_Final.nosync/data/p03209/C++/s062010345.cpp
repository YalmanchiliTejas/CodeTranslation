#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N, X;
ll two[52];

ll ans(ll n, ll x){
	if(n == 0){
		if(x == 0){
			return 0;
		}else{
			return 1;
		}
	}
	if(x == 2*two[n+1] - 3){
		return two[n+1] - 1;
	}else if(x > two[n+1]-1){
		return two[n] + ans(n-1, x-two[n+1]+1);
	}else if(x == two[n+1]-1){
		return two[n];
	}else if(x == 0){
		return 0;
	}else{
		return ans(n-1, x-1);
	}
}

int main(){
	cin >> N >> X;
	two[0] = 1;
	for(int i=1; i<N+2; i++){
		two[i] = two[i-1]*2;
	}
	cout << ans(N, X) << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
	
const int N = 3001 ;
typedef long long ll  ; 

ll dp[N][N][2] ;
int a[N] ;

ll calc(int l , int r , bool c){

		
	if (l == r){
		if (c)
			return -a[l];
		else 
			return a[l] ; 
	}
	
	ll &ret = dp[l][r][c] ; 
	if (ret != -1)
		return ret ; 
	
	if (!c)
		ret = max(1ll * calc(l+1 , r , !c)+a[l] , 1ll * calc(l , r-1 , !c)+a[r]) ; 
	else 
		ret = min(1ll * calc(l+1 , r , !c)-a[l] , 1ll * calc(l , r-1 , !c)-a[r]) ; 
	
	return ret ; 
}
int main() {
	int n ; 
	scanf("%d" , &n) ; 
	
	memset(dp , -1 , sizeof dp) ; 
	
	for (int i = 0 ; i<n ; ++i) {
		scanf("%d" , &a[i]) ; 
	}
	ll ans = calc(0 , n-1 , 0) ; 
	printf("%lld" , ans) ; 
	return 0;
}
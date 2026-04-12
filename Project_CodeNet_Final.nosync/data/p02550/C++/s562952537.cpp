#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int32_t main(){
	int vis[N] = {} ;
	int cnt = 0 ;
	int n , x , m ;
	cin >> n >> x >> m ;
	int mod = m ;
	int sum = 0 ;
	while(!vis[x] && cnt < n){
		vis[x] = cnt ;
		sum += x ;
		x = (x*x) % mod ;
		cnt++ ;
	}
	if(cnt == n){
		cout << sum ;
	} else {
		n -= cnt ;
		int t = cnt - vis[x] ;
		int cur = 0 ;
		for(int i = 0 , cx = x ; i < t ; i++){
			cur += cx ;
			cx = (cx * cx ) % mod ;
		}
		sum += (n / t)*cur ;
		n %= t ;
		cnt = 0 ;
		while(cnt < n){
			sum += x ;
			x = (x*x) % mod ;
			cnt++ ;
		}
		cout << sum ;
	}
	return 0 ;
}


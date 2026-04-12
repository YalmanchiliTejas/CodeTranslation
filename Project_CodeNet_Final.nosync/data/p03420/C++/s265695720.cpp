#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	ll n,k;
	cin >> n >> k;
	
	if(k == 0){
		cout << n*n << endl;
		return 0;
	}
	
	ll ret = 0;
	for(ll b = k+1 ; b <= n ; b ++){
		ll x = (n+1)/b;
		ll y = (n+1)%b;
		ret += x*(b-k) + max(0LL,y-k);
	}
	cout << ret << endl;
}
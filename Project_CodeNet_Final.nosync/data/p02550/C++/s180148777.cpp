#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;
const int inf = 99999999;

using namespace std;

void print2(ll a , ll b){cout << a << " : " << b << endl;}
void print3(ll a , ll b , ll c){cout << a << " : " << b << " : " << c << endl;}

int main(){
	ll n,x,m;
	cin >> n >> x >> m;
	
	vector<ll> v = {};
	vector<ll> memo(m+100,-1);
	
	ll r = 0 , l = 0 , now = x;

	for(ll i = 0; i < n; i++){
		if(i == 0){
			now = x;
		}else{
			now = now*now;
		}
		now %= m;
		if(memo[now] == -1){
			memo[now] = i;
			v.push_back(now);
			continue;
		}else{
			l = memo[now];
			r = i - memo[now];
			break;
		}
	}
	
	ll ans = 0;
	if(l == 0 && r == 0){
		for(ll i = 0; i < v.size(); i++){
			ans += v[i];
		}
		cout << ans << endl;
		return 0;
	}
	
	ll cnt = (n - l) / r;
	ll h = (n - l) % r;
	
	for(int i = 0; i < l; i++){
		ans += v[i];
	}
	
	ll temp = 0;
	for(int i = l; i < l + r; i++){
		temp += v[i];
	}
	ans += cnt * temp;
	
	for(int i = l; i < l + h; i++){
		ans += v[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
 
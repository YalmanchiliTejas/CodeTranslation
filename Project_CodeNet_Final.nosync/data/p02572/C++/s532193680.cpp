#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1000000007;

ll n;
ll a[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) cin >> a[i];
	ll sum = 0, sum_pro = 0;
	rep(i, n){
		sum_pro = (sum_pro + sum * a[i]) % Mod;
		sum = (sum + a[i]) % Mod;
	}
	cout << sum_pro << endl;
	return 0;
}
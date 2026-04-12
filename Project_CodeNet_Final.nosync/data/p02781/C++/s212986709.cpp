#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
template <class T>
T powmod(T a, ll b, ll m){
	T res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

int cnt[101];
int C(int n, int r){
	if(n < r){
		return 0;
	}
	int res = 1;
	int v1 = n - r, v2 = r;
	if(v1 < v2)
		swap(v1, v2);
	for(int i = v1 + 1; i <= n; i++){
		res *= i;
	}
	for(int i = 1; i <= v2; i++){
		res /= i;
	}
	return res;
}

int mod = 1e9 + 7;
int32_t main(){
	cnt[0] = 0;
	string s;
	cin >> s;
	int n = s.size();
	int k;
	cin >> k;
	int ans = 0;
	if(k == 1){
		ans = s[0] - '0';
		ans += 9 * (n - 1);
	}else if(k == 2){
		bool x = false;
		for(int i = 1; i < n; i++){
			if(x){
				ans += 9;
			}else{
				ans += s[i] - '0';
			}
			if(s[i] != '0'){
				x = true;
			}
		}
		ans += C(n - 1, 2) * 9 * 9;
		ans += C(n - 1, 1) * (s[0] - 1 - '0') * 9;
	}else{
		bool x = false;
		for(int i = 1; i < n; i++){
			bool y = x;
			for(int j = i + 1; j < n; j++){
				if(x){
					ans += 9 * 9;
				}else if(y){
					ans += (s[i] - '0') * 9;
				}else{
					if(s[i] != '0')
						ans += (s[i] - '0' - 1) * 9 + s[j] - '0';
				}
				if(s[j] != '0'){
					y = true;
				}
			}
			if(s[i] != '0'){
				x = true;
			}
		}
		ans += C(n - 1, 3) * 9 * 9 * 9;
		ans += C(n - 1, 2) * (s[0] - 1 - '0') * 9 * 9;	
	}
	cout << ans << endl;
}
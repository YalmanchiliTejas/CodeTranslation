#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

int main() {
	string n;
	ll k;
	cin >> n >> k;
	if(k == 3 && n.size() < 3){
		cout << "0" << endl;
		return 0;
	}
	if(k == 2 && n.size() < 2){
		cout << "0" << endl;
		return 0;
	}
	if(k == 1){
		cout << (n.size() - 1) * 9 + (ll) (n[0] - '0') << endl;
		return 0;
	}
	ll ans = 0;
	if(k == 2){
		for(ll i = 2; i < n.size(); i++){
			ans += (i-1) * 81;
		}
		ans += (int) (n[0] - '0' - 1) * (n.size() - 1) * 9;
		string tmp = n;
		for(int i = 1; i < n.size(); i++) tmp[i] = '0';
		
		for(int keta = n.size() - 1; keta > 0; keta--){
			for(int i = 1; i <= 9; i++){
				tmp[keta] = (char) (i + '0');
				if(tmp <= n) ans++;
				else{
					cout << ans << endl;
					return 0;
				}
			}
			tmp[keta] = '0';
		}
		cout << ans << endl;
		return 0;
	}
	if(k == 3){
		for(ll i = 3; i < n.size(); i++){
			ans += (i - 1) * (i - 2) / 2 * 729;
		}
		ans += (ll) (n[0] - '0' - 1) * (n.size() - 1) *(n.size() - 2) / 2* 81;
		string tmp = n;
		for(int i = 1; i < n.size(); i++) tmp[i] = '0';
		
		for(int keta1 = n.size() - 2; keta1 > 0; keta1--){
			for(int i = 1; i <= 9; i++){
				for(int keta2 = n.size() - 1; keta2 > keta1; keta2--){
					for(int j = 1; j <= 9; j++){
						tmp[keta1] = (char) (i + '0');
						tmp[keta2] = (char) (j + '0');
						if(tmp <= n) ans++;
						else{
							cout << ans << endl;
							return 0;
						}
					}
					tmp[keta2] = '0';
				}
			}
			tmp[keta1] = '0';
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[500005];
ll y,m,d;
ll ans;
ll x[500005];
ll l,r;
ll n;

bool solve(){
	cin >> n >> l >> r;
	if(n == 0)return false;
	for(int i=0;i<n;i++){
		cin >> x[i];
	}
	ans = 0;
	for(int i=l;i<=r;i++){
		//check i
		bool used = false;
		for(int j=0;j<n;j++){
			if(i % x[j] == 0){
				if(j % 2 == 0){
					used = true;
					ans++;
					break;
				}else{
					used = true;
					break;
				}
			}
		}
		if(!used){
			if(n % 2 == 0){
				ans++;
			}
		}
	}
	cout << ans << endl;
	return true;

}




int main(){
	while(solve()){}
	return 0;
}

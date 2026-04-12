#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<int(n); i++)
typedef long long ll;
using namespace std;

int main(){
	int N; cin >> N;
	ll x[N], y[N], rma = 0, rmi = 1e18, bma = 0, bmi = 1e18;
	rep(i, N){
		cin >> x[i] >> y[i];
		if(x[i] < y[i]) swap(x[i], y[i]);
		if(rma < x[i]) rma = x[i];
		if(bma < y[i]) bma = y[i];
		if(rmi > x[i]) rmi = x[i];
		if(bmi > y[i]) bmi = y[i];
	}
	ll ans = (rma - rmi)*(bma - bmi), ma = 0, mi = 1e18;
	vector<pair<ll, ll>> arr;
	rep(i, N){
		if(y[i] == rma || x[i] == bmi || (x[i] == rma && y[i] == bmi)){
			cout << ans << endl;
			return 0;
		}
		if(x[i] == rma && ma < y[i]) ma = y[i];
		if(x[i] == rma && mi > y[i]) mi = y[i];
		if(y[i] == bmi && ma < x[i]) ma = x[i];
		if(y[i] == bmi && mi > x[i]) mi = x[i];
		if(x[i] != rma && y[i] != bmi) arr.push_back({y[i], x[i]});
	}
	sort(arr.begin(), arr.end());
	ll s[2][arr.size()];
	rep(x, 2)rep(i, arr.size()){
		if(i==0) s[x][i] = arr[i].second;
		else if(x==0) s[x][i] = min(s[x][i-1], arr[i].second);
		else s[x][i] = max(s[x][i-1], arr[i].second);
	}
	ll d = 1e18;
	rep(i, arr.size()+1){
		if(i==0){
			if(d > max(ma, arr[arr.size()-1].first) - min(mi, arr[i].first)){
				d = max(ma, arr[arr.size()-1].first) - min(mi, arr[i].first);
			}
		}else{
			if(d > max(ma, max(s[1][i-1], arr[arr.size()-1].first)) - min(mi, min(arr[i].first, s[0][i-1]))){
				d = max(ma, max(s[1][i-1], arr[arr.size()-1].first)) - min(mi, min(arr[i].first, s[0][i-1]));
			}
		}
	}
	cout << min(ans, d*(rma - bmi)) << endl;
	return 0;
}

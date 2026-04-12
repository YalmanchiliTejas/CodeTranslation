#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;
typedef vector<map<lli,lli>> graph;

lli n;
vll a;
vll b_,_b;

int main(){
	cin >> n;
	a = vll(n);
	for(lli i = 0;i < n;i++) cin >> a[i];
	for(lli i = 0;i < n;i++){
		if(i%2){
			_b.push_back(a[i]);
		}else{
			b_.push_back(a[i]);
		}
	}
	if(n%2 == 0){
		for(lli i = _b.size()-1;i >= 0;i--){
			cout << _b[i] << " ";
		}
		for(lli i = 0;i < b_.size();i++){
			cout << b_[i];
			if(i != b_.size()-1) cout << " ";
		}

	}else{
		for(lli i = b_.size()-1;i >= 0;i--){
			cout << b_[i] << " ";
		}
		for(lli i = 0;i < _b.size();i++){
			cout << _b[i];
			if(i != _b.size()-1) cout << " ";
		}
	}
	cout << endl;
	return 0;
}
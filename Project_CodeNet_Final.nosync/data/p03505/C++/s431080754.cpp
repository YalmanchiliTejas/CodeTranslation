#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
	ll k, a, b; cin >> k >> a >> b;
	ll po = k - a;
	if(po <= 0){
		cout << 1 << endl;
	}else if(b - a >= 0){
		cout << -1 << endl;
	}else{
		ll yo = po / (a - b) + (po % (a - b) != 0);
		cout << yo * 2 + 1 << endl;
	}
	return 0;
}
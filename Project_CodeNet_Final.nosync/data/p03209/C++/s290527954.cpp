#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, X;
vector<ll> total{1}, patty{1};

ll func(ll n, ll x){
	if(n == 0){
		if(x <= 0) return 0;
		else return 1;
	}else if(x <= 1 + total[n-1]){
		return func(n-1,x-1);
	}else{
		return patty[n-1] + 1 + func(n-1, x-2-total[n-1]);
	}
}

int main(){
	cin >> N >> X;
	for(int i(0);i<N;++i){
		total.push_back(2*total[i]+3);
		patty.push_back(2*patty[i]+1);
	}
	cout << func(N, X) << endl;
	return 0;
}
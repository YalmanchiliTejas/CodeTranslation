#include <iostream>
#include <math.h>
using namespace std;
#define ll long long

int N;
ll X;


ll sub_solve(ll n){
	if(n == 0) return 0;

	ll ans = N;

	for(int i=0;i<N;i++){
		ans += 2 * (n / (4 * (ll)pow(2,i)));
		if(n % (4 * (ll)pow(2,i)) == 0) ans--;
	}
	return ans+n;
}


void solve(){
	ll head = 0;
	ll tail = X;
	ll cur = X/2;

	while(!(sub_solve(cur) <= X && X < sub_solve(cur+1))){
		if(sub_solve(cur) < X){
			head = cur;
			cur = (cur + tail)/2;
		}else{
			tail = cur;
			cur = (head + cur)/2;
		}
	}
	cout << cur << endl;
}


int main(){
	cin >> N >> X;
	solve();
	return 0;
}
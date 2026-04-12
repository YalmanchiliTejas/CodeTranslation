#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ex[64];


ll solve(ll n, ll x){
	if(x==0)
		return 0;
	if(n==0)
		return 1;
	if(x<(2*ex[n]-1))
		return solve(n-1,x-1);
	else if(x==2*ex[n]-1)
		return solve(n-1,x-2)+1;
	else
		return 2*ex[n-1] + solve(n-1,x-2*ex[n] + 1);
}

int main(){

	ll n,x;
	cin >> n >> x;
	ex[0] = 1;
	for(int i=1;i<60;i++)
		ex[i] = ex[i-1]*2;
	cout << solve(n,x);
	

}
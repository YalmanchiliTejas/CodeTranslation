// D - Christmas
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(int n, ll x){
	if(n==0) return x<=0? 0:1;
	ll Ln_1 = (1LL<<n+1) - 3;//L[n-1]
	ll Pn_1 = (1LL<<n) - 1;//P[n-1]
	ll m = Ln_1 + 2;
	if(m > x) return f(n-1, x-1);
	else if(m < x) return Pn_1 + 1LL + f(n-1, x-m);
	else return Pn_1 + 1LL;
}

int main(){
	int N; ll X; cin>>N>>X;
	cout<< f(N, X) <<endl;
}
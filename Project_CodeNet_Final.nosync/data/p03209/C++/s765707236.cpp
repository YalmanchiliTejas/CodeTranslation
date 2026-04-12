// D - Christmas
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> L, P;

ll f(int n, ll x){
	if(n==0) return x<=0? 0:1;
	ll m = L[n]/2 + 1;
	//left: xの補正: L[n-1]範囲の前にある B が邪魔だ
	if(m > x) return f(n-1, x-1);
	//right: xの補正: L[n-1]範囲の前にある B+L[n-1]+P が邪魔だ
	else if(m < x) return P[n-1] + 1LL + f(n-1, x-m);
	//mid
	else return P[n-1] + 1LL;
}

int main(){
	int N; ll X; cin>>N>>X;

	L.push_back(1);
	P.push_back(1);
	for(int i=0; i<N; ++i){
		L.push_back(L[i]*2LL + 3LL);
		P.push_back(P[i]*2LL + 1LL);
	}

	cout<< f(N, X) <<endl;
}
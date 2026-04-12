// D - Christmas
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> A, P;

ll f(int N, ll X){
	if(N == 0) return X<=0? 0:1;
	else if(X <= 1LL+A[N-1]) return f(N-1, X-1);
	else return P[N-1] + 1LL + f(N-1, X-2LL-A[N-1]);
}

int main(){
	int N; ll X; cin>>N>>X;

	A.push_back(1);
	P.push_back(1);
	for(int i=0; i<N; ++i){
		A.push_back(A[i]*2LL + 3LL);
		P.push_back(P[i]*2LL + 1LL);
	}

	cout<< f(N, X) <<endl;
}
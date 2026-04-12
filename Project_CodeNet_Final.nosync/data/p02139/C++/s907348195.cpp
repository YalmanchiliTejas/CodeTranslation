#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

vector<pair<long long int, long long int>>ps;
long long int g(long long int x, long long int place) {
	return ps[x].first + ps[x].second*(place);
}

int main() {
	int N,Q;cin>>N>>Q;
	int k=0;
	for (int i = 0; i < Q;++i) {
		int a,b;cin>>a>>b;
		if (a == 1) {
			k+=b;
			k%=N;
		}
		else {
			if(k+b==N)cout<<N<<endl;

			else cout<<(k+b)%N<<endl;
		}
	}
	return 0;
}

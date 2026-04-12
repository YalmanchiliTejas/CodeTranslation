#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int N,K;
	string S;
	cin >> N >> S >> K;

	rep(i,N)
		if(S.at(K-1) != S.at(i))
			S.at(i) = '*';
	cout << S << endl;	
}
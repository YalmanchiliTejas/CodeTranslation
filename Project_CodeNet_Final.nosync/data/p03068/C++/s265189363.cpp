#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	string S;
	cin >> N >> S >> K;

	rep(i, N){
		if(S[i] == S[K-1]) cout << S[i];
		else cout << "*";
	}

	cout << endl;
}

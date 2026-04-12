#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int K,N;
	string S;
	cin >> N >> S >> K;
	for(int i(0);i<N;++i){
		if(S[K-1] != S[i]) cout << '*';
		else cout << S[i];
	}
	cout << endl;
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

int main(){

	string S;
	int N,K;

	cin >> N;
	cin >> S;
	cin >> K;
	char moji = S[K-1];
	for (int i = 0 ; i < N ; i++){
		
		if (S[i]!=moji){
			S[i]='*';
		}
	}

	cout << S <<endl;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(){
	int N, K;
	string S;

	cin >> N;
	cin >> S;
	cin >> K;

	char chk = S[K-1];

	for(int i = 0; i < N; i++){
		if(S[i] != chk)
			S[i] = '*';
	}

	cout << S << endl;
}
#include<iostream>
#include<string>

using namespace std;

int main(){
	int N, K;
	string S;
	cin >> N >> S >> K;

	char hidden;
	for(int i = 0; i < N; ++i){
		if(i == K-1) hidden = S[i];
	}

	for(int i = 0; i < N; ++i){
		if(S[i] != hidden) cout << "*";
		else cout << S[i];
	}

	cout << endl;

	return 0;
}

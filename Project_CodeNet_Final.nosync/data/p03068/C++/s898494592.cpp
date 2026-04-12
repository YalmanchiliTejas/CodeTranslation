#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N >> S >> K;
	string T="";
	for(int i=0; i<N; ++i){
	    T += (S[i]==S[K-1] ? S[i] : '*');
	}
	cout << T << endl;
	return 0;
}

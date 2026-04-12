#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
	uint16_t N,K;
	string S;
	cin >> N >> S >> K;
	char Letter = S[K - 1];
	for(uint16_t i = 0;i < N;i++){
		if(S[i] != Letter)
			S[i] = '*';
	}
	cout << S << endl;
	
	return 0;
}

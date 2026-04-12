#include <iostream>
using namespace std;

int main(void) {
  	int N,K;
  	string S;
  	cin >> N >> S >> K;
  	--K;
  	for(int i=0; i<N; ++i) {
    	if(S[i]!=S[K]) S[i]='*'; 
    }
  	cout << S << "\n";
	return 0;
}
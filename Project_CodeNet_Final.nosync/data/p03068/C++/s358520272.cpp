#include<iostream>

int main(){
	int N, K;
	char *S;
	
	std::cin >> N;
	S = new char[N];
	for(int i=0; i < N; i++){
		std::cin >> S[i];
	}
	std::cin >> K;

	char ch = S[K - 1];

	for(int i=0;i<N;i++){
		if(ch != S[i]){
			S[i] = '*';
		}
	}

	std::cout << S << std::endl;

	delete[] S;

	return 0;
}
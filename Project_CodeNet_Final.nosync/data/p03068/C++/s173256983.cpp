#include <iostream>

int main(){
	std::string S;
	int N,K;
	std::cin>>N>>S>>K;

	char muta = S[K-1];

	for(int i=0;i<N;++i){
		if(S[i] != muta){
			S[i] = '*';
		}
	}
	std::cout<<S;
	return 0;
}

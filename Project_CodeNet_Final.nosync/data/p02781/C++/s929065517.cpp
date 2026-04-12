#include <iostream>
using namespace std;

uint64_t srv_f(string N, int c, int K)
{
	int l = N.length() - c;
	if(l < K){
		return 0;
	} else {
		if(K == 0){
			return 1;
		} else if(K == 1){
			return 9 * l;
		} else if(K == 2){
			return 9 * 9 * l * (l-1) / 2;
		} else if(K == 3){
			return 9 * 9 * 9 * l * (l-1) * (l-2) / 3 / 2;
		}
	}
}

uint64_t srv(string N, int c, int K)
{
	if(K == 0){
		return 1;
	}
	if(N.length() == c){
		return 0;
	}

	char t = N[c];
	if(t == '0'){
		return srv(N, c+1, K);
	} else {
		return srv_f(N, c+1, K)
			+ (t - '1') * srv_f(N, c+1, K-1)
			+ srv(N, c+1, K-1);
	}
}

int main()
{
	string N;
	int K;
	cin >> N >> K;

	cout << srv(N, 0, K);

	return 0;
}

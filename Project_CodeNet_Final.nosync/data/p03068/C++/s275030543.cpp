#include<iostream>
using namespace std;

int main()
{
	int N,K;
	cin >> N;
	string S;
	cin  >>S >>K;

	for (int i=0;i<N;i++){
		if (S[i] != S[K-1]){
			S[i] = '*';
		}
	}
	cout << S;

	return 0;
}
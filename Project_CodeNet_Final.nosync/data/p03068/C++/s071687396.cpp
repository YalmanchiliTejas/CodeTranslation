#include <bits/stdc++.h>
using namespace std;


int main()
{
	string S;
	int N, K;
	char A;
	cin >> N >> S >> K;
	A = S.at(K-1);
	for (int i=0;i<N;i++){
      	if (S.at(i)!=A)S.at(i) = '*';
	}
	cout << S << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	int N,K;
	string S;
	cin >> N >> S >> K;

	char x=S.at(K-1);
	for(int i=0;i<N;i++){
		if(S.at(i)==x)	cout << S.at(i);
		else	cout << "*";
	}
	cout << endl;

	return 0;
}

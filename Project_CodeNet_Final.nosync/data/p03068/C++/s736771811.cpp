#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



int main(){
	int N, K;
	char X;
	char s[10];
	cin >> N;
	for (int i = 0; i < N; i++)		cin >>s[i];
	cin >> K;
	X = s[K - 1];
	for (int i = 0; i < N; i++) {
		if (s[i] == X) {}
		else s[i] = '*';
	}
	for (int i = 0; i < N; i++)
	{
		cout << s[i];
	}

	return 0;
}
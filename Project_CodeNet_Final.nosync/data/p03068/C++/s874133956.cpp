#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int N,K;
	cin >> N;
	char S[100];
	for (int i = 0; i < N; i++)	{cin >> S[i];}
	cin >> K;
	for (int i = 0; i < N; i++)
	{
		if (S[i]!=S[K-1]) {S[i] = '*';}
	}
	for (int i = 0; i < N; i++)	{cout << S[i];}
}

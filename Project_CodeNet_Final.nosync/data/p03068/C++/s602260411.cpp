#include<iostream>
#include<string>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<climits>
#include<cmath>
#include<map>
#include<vector>
#define INF INT_MAX
using namespace std;

int main(){
	int N, K;
	string S;
	char ans;
	cin >> N >> S >> K;
	ans = S[K - 1];
	for (int i = 0; i < N; i++){
		if (ans != S[i]){
			S[i] = '*';
		}
	}

	cout << S << endl;

	return 0;
}
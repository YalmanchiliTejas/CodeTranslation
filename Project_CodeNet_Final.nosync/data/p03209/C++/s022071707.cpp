#include"iostream"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<list>
#include<map>
#include<string>
#include<algorithm> 
#include <queue> 
#include <sstream>
#include <fstream>
#include<cmath>
#define INF 1000000000
#define LL long long
using namespace std;

vector<LL> v;

long long N, M,K, ans, A[100000],use[10];
string s;
LL P[50],al[50];//パティと全体

LL burg(LL N, LL X) {
	if (P[0] == -1) {
		P[0] = 1;
		for (int i = 1; i < N; i++) {
			P[i] = 2 * P[i - 1] + 1;
		}
	}
	if (al[0] == -1) {
		al [0] = 1;
		for (int i = 1; i < N; i++) {
			al[i] = 2 * al[i - 1] + 3;
		}
	}
	if (N == 0) {
		if (X > 0)	return 1;
		else return 0;
	}
	else {
		if (X <= al[N-1]+1) {
			return burg(N - 1, X - 1);
		}
		else {
			return P[N - 1] + 1 + burg(N - 1, X - (al[N - 1] + 1) - 1);
		}
	}
}

int main() {
	cin >> N>>K;
	P[0] = -1;
	al[0] = -1;
	cout << burg(N,K)<<endl;
	return 0;
}
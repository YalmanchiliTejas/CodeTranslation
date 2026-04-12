#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<string>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;

int main(){
	int N, Y[200000];
	vector<int> X;

	scanf("%d", &N);
	int i;
	REP(i, N){
		cin >> Y[i];
		X.push_back(Y[i]);
	}

	sort(X.begin(), X.end());

	REP(i, N){
		if (Y[i]<=X[(N-1)/2]){
			cout << X[(N-1) / 2 + 1] << endl;
		}
		else{
			cout << X[(N -1)/ 2] << endl;
		}
	}


	return 0;
}
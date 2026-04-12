
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N, X, M;
	cin >> N >> X >> M;
	
	
	long long A[100001];
	
	long long sum = X;
	long long Ai = X, Ai1;
	A[1] = X;
	
	for(long long i = 1; i < N; i++) {
		Ai1 = (Ai * Ai) % M;
		//cout << Ai1;

		Ai = Ai1;
		A[i + 1] = Ai1;
		for(int j = 1; j <= i; j++) {
			if(A[j] == Ai1) {
				// 区間を求める
				long long start = j;
				long long end   = i;
				long long period = i - j + 1;
				
				// 残り区間長さ
				long long sur = (N - i - 1) % period;
				long long div = (N - i - 1) / period;
				
				long long ssum = 0;
				long long ssum2 = 0;
				for(int k = start; k <= end; k++) {
					ssum += A[k];
				}
				for(int k = start; k <= start + sur; k++) {
					ssum2 += A[k];
				}
				// sum肉緩和を加算
				sum += ssum * div;
				sum += ssum2;
				// 端数処理
				//i = N - sur;
				cout << sum << endl;
				return 0;
			}
		}
				sum += Ai1;
	}
	
	cout << sum << endl;
	
	return 0;
}

//1000000000000001
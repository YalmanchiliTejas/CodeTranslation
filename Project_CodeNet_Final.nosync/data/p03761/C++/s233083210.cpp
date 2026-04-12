#include<iostream>
#include <string> 
#include <vector>     

#define INF 1000000000
using namespace::std;

pair<int, string> p[500000] ;//firstに右secondに左


long Lmax(long x, long y) {
	if (x > y)return x;
	return y;
}

int max(int x, int y) {
	if (x > y)return x;
	return y;
}

long Lmin(long x, long y) {
	if (x < y)return x;
	return y;
}


int min(int x, int y) {
	if (x < y)return x;
	return y;
}

int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}


double houwa;
int N,C,H, M,K,W,al[50][26],ltl[26];
string S,s;
char a[50][50],b[26];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < 26; i++) {
			b[i] = 'a' + i;
			ltl[i] = 100;
			for (int k = 0; k < 50; k++) {
				if (a[j][k] == 'a' + i) {
					al[j][i]++;
				}
			}
		}
	}
for (int i = 0; i < 26; i++) {
	for (int j = 0; j < N; j++) {
		ltl[i] = min(ltl[i], al[j][i]);
		}
	}

for (int i = 0; i < 26; i++) {
	for (int j = 0; j < ltl[i]; j++) {
		cout << b[i];
	}
}
cout <<endl;
	return 0;
}



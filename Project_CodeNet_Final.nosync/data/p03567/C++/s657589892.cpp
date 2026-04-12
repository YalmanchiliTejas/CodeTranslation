#include<iostream>
#include <string> 
#include <vector>     

#define INF 1000000000
using namespace::std;




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

bool c;
int N,C,H, M,K,W,al[50][26],ltl[26];
string S,s;
char a[50][50],b[26];
int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') {
			if (S[i + 1] == 'C') {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

cout <<"No"<<endl;
	return 0;
}



#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; string S; int K;
	cin >> N >> S >> K;
	char c=S[K-1];
	for (int i = 0; i < N; i++) {
		cout << (S[i] == c ? c : '*');
	}

}

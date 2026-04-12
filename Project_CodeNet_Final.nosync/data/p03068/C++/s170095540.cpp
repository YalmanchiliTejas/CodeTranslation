#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;
#define print(x) cout<<(x)<<endl

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007

int main() {
	int N, K;
	string S;
	string out;
	cin >> N >> S >> K;
	for (int i = 0; i < N; i++) {
		if (S[i] == S[K - 1])out+=S[i];
		else out += "*";
	}
	print(out);



	return 0;
}
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
	int N;
	cin >> N;
	cout << N * 800 - int(N / 15) * 200 << endl;
}


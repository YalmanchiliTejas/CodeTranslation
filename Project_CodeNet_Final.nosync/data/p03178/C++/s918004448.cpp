#include <cstdio>
#include <algorithm>	
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long LL;
typedef unsigned int uii;
typedef pair<int,int> pii;
typedef unsigned long long uLL; 
typedef vector<int> vii; 
const int maxn = 1e4 + 5;
const int M = 1e9 + 7;
LL d[maxn][105];

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int K;
	cin >> s >> K;
	reverse(all(s));
	int n = (int)s.size();
	d[0][0] = 1;
	for(int i = 0; i < 10; ++i){
		++d[1][i % K];
	}
	for(int i = 2; i < n; ++i){
		for(int j = 0; j < K; ++j){
			for(int k = 0; k < 10; ++k){
				d[i][j] = (d[i][j] + d[i - 1][(j - k + 1000 * K) % K]) % M;
			}
			// cout << d[i][j] << ' ';
		}
		// cout << endl;
	}
	LL res = 0, num = 0;
	for(int i = n - 1; i >= 0; --i){
		int x = s[i] - '0';
		for(int j = 0; j < x; ++j){
			int t = (K - (num + j) % K) % K;
			res = (res + d[i][t]) % M;
			// cout << res << endl;
		}
		num += x;
	}
	res = (res - 1 + M) % M;
	if(num % K == 0) res = (res + 1) % M;
	cout << res << endl;
	return 0;
}
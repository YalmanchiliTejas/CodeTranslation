#include<iostream>
#include<string>
#include<random>
#include<chrono>
#include<map>
#include<fstream>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const long long mod = 1000000007;
const long long inf = 11451419198109130;
typedef pair<int, int> P;
int bp(int i, int j) {
	if (i) {
		if (i + 1 >= pow(2, j + 1))
		{
			if (i + 3 == pow(2, j + 2)) return pow(2, j + 1) - 1;
			else return pow(2, j) + bp(i - pow(2, j + 1) + 1, j - 1);
		}
		else return bp(i - 1, j - 1);
	}
	else return 0;
}
signed main() {
	int N, X;
	cin >> N >> X;
	cout << bp(X, N) << endl;
	return 0;
}
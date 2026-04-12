#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
signed main()
{
	int N;
	cin >> N;
	vector<int>H(N);
	rep(i, N)cin >> H[i];
	vector<bool>v(N, true);
	for (int i = 0; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (H[i] < H[j])v[i] = false;
		}
	}
	int cnt = 0;
	rep(i, N)if (v[i] == true)cnt++;
	cout << cnt;
}
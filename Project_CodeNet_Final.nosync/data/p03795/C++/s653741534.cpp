#include <iostream>
#include<algorithm>
#include<string>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#pragma region Macros
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define all(x) (x).begin(),(x).end()
#define swap(a,b) (a += b,b = a - b,a -= b)
#define CEIL(a,b) ((a+b-1)/b)
int GCD(int a, int b) // assuming a,b >= 1
{
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}
int LCM(int a, int b) // assuming a,b >= 1
{
	return  a * b / GCD(a, b);
}
inline bool BETWEEN(int x, int min,int max) {
	if (min <= x && x <= max)
		return true;
	else
		return false;
}
using namespace std;
#pragma endregion
signed main() {
	int N;
	cin >> N;
	cout << 800*N - (N/15)*200;
}
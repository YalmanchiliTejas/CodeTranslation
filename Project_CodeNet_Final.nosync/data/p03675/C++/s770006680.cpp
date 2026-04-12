
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<numeric>
#include<vector>
#include<tuple>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
typedef long long ll;
const int MOD = 1e9 + 7;
ll N, a[200000];
ll b[200000];
int main(void)
{
	cin >> N; ll cnt = 0;
	FOR(i, 0, N)cin >> a[i];
	for (int i = N-1; i >= 0; i -= 2) {
		b[cnt]=a[i];
		cnt++;
	}
	for (int i = N % 2; i < N; i += 2) {
		b[cnt] = a[i];
		cnt++;
	}
	FOR(i, 0, N) {
		cout << b[i];
		if (i != (N - 1))cout << " ";
	}
	cout << endl;
	return 0;
}

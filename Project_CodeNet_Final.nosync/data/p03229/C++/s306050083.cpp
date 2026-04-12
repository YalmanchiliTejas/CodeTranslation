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
ll a[100010],N,ans1=0,ans2=0;
int main(void)
{
	cin >> N;
	FOR(i, 0, N)cin >> a[i];
	sort(a, a + N);
	ll i = 0;
	if (N % 2 == 1) {
		FOR(k, 0, (N - 1) / 2 - 1) {
			ans1 -= 2 * a[i];i++;
		}
		ans1 -= a[i] + a[i + 1]; i += 2;
		FOR(k, 0, (N - 1) / 2) {
			ans1 += 2 * a[i];i++;
		}
		i = 0;
		FOR(k, 0, (N - 1) / 2) {
			ans2 -= 2 * a[i];i++;
		}
		ans2 += a[i] + a[i + 1]; i += 2;
		FOR(k, 0, (N - 1) / 2 - 1) {
			ans2 += 2*a[i]; i++;
		}
	}
	else {
		FOR(k, 0, (N / 2)-1) {
			ans1 -= a[i] * 2; i++;
		}
		ans1 -= a[i]-a[i+1]; i+=2;
		FOR(k, 0, (N / 2) - 1) {
			ans1 += 2 * a[i]; i++;
		}
	}
	ct(max(ans1,ans2));
	return 0;
}

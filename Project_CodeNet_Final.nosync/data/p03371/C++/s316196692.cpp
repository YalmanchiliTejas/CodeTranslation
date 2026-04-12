#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
int main() {
	ll A, B, C, X, Y;
	ll m = 1e13;
	scanf("%lld%lld%lld%lld%lld", &A, &B, &C, &X, &Y);
	rep(i, 0, 1000000){
		m = min(i * 2 * C + max((ll)0, X - i) * A + max((ll)0, Y - i) * B, m);
	}
	printf("%lld", m);
	return 0;
}
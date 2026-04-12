#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
int main(){
	ll n;	scanf("%lld", &n);
	printf("%lld\n", n * 800 - n / 15 * 200);
	return 0;
}
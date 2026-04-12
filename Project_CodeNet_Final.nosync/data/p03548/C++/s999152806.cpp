#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
ll mod = 1000000007;
int main()
{
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	printf("%d\n", (x - z) / (y + z));
}
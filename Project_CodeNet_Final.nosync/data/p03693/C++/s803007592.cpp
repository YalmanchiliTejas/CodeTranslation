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
	int a, b, c;
	cin >> a >> b >> c;
	//cout << min(min(a + b, b + c), c + a) << endl;
	printf(((b*10+c)%4==0) ? "YES\n" : "NO\n");
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <stdio.h>

using namespace std;

#define INF 2000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;


int main()
{
	ll n;
	cin >> n;

	ll a = n / 15;
	ll ans = 800 * n - a * 200;

	cout << ans << endl;

}

#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define PI 3.1415926535897932384626433832795
#define pii pair <int, int>
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define N 100010

using namespace std;

int a, b, c, x, y;

int main()
{
	cin >> a >> b >> c >> x >> y;
	
	int ans = 1e9;
	for(int i = 0; i <= 200000; i += 2) {
		int sum = i*c;
		
		if(i / 2 <= x) sum += (x - i / 2)*a;
		if(i / 2 <= y) sum += (y - i / 2)*b;
		
		ans = min(ans, sum);
	}
	
	cout << ans;
}
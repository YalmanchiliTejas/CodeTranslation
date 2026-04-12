#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cstring>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))
#define fname "searching"

const int inf = (int)1e9;
const ll INF = (ll)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = (int)1e9 + 7;

int a, b, c;

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen(fname".in", "r", stdin);
	// freopen(fname".out", "w", stdout);
	scanf("%d%d%d", &a, &b, &c);
	int x = a * 100 + b * 10 + c;
	if(x % 4 == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iomanip>

using namespace std;

/********** TEMPLATE STARTS HERE ***********/

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define gcd __gcd 
#define digits(n) (int)(log10(n) + 1)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <long long> vl;
typedef vector <pll> vll;
typedef vector <pii> vii;

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;

template <typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template <typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

/*********** TEMPLATE ENDS HERE *************/

main()
{
	IOS
	
	int A, B, C, x, y;
	
	cin >> A >> B >> C >> x >> y;
	
	int money = A * x + B * y;
	
	if(x > y)
	{	
		money = min(money, C * x * 2);
		money = min(money, C * y * 2 + (x - y) * A);
	}
	else
	{
		money = min(money, C * x * 2 + (y - x) * B);
		money = min(money, C * y * 2);
	}
	
	cout << money;
}
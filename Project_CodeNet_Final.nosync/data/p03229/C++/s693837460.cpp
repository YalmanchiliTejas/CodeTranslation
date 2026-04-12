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

const int DIM = 1e5 + 7;

#define int long long

vi arr;
int v[DIM];

main()
{
	IOS
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	
	sort(v + 1, v + 1 + n);
	
	int l = v[1];
	int r = v[1];
	
	int st = 2;
	int dr = n;
	
	bool le = 1;
	bool ri = 1;
	
	int s = 0;
	
	while(st <= dr)
	{
		int sl = 0;
		int sr = 0;
		
		if(le == 1)
			sl = abs(l - v[dr]);
		else
			sl = abs(l - v[st]);
		
		if(ri == 1)
			sr = abs(r - v[dr]);
		else
			sr = abs(r - v[st]);
		
		if(sl > sr)
		{
			if(le == 1)
			{
				le = 0;
				l = v[dr--];
			}
			else
			{
				le = 1;
				l = v[st++];
			}
			
			s += sl;
		}
		else
		{
			if(ri == 1)
			{
				ri = 0;
				r = v[dr--];
			}
			else
			{
				ri = 1;
				r = v[st++];
			}
			
			s += sr;
		}
	}
	
	cout << s;
}
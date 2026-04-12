#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<cstdio>
#include<stack>
#include<queue>
#include<fstream>
#include<cstdio>
#include<deque>
#include<iomanip>
#include <random>

using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);(i)--)
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
const double pi = acos(-1.0);

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<ll> dll;
ll mod = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ax = (a*x + b * y);
	ll ay = 0, by = 0;;
	if(x > y) {
		rep(i, y*2) {
			ay += c;
			//cout << ay << endl;
		}
		ll bx = x;
		x -= y;
		ay += (a*x);
		bx *= 2;
		by = c * bx;
		//cout << by << x;
		MIN(ay, by);
	}
	else {
		rep(i, x*2) {
			ay += c;
			//cout << ay << endl;
		}
		ll bx = y;
		y -= x;
		ay += (b*y);
		bx *= 2;
		by = (c*bx);
		//cout << by;
		MIN(ay, by);
	}
	//cout << ax << " " << ay << endl;
	cout << min(ax, ay) << endl;
	return 0;
}
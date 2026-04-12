#include <iostream>
#include<algorithm>
#include <vector>
#include<map>
#include<deque>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define max(x,y) (((x)>(y)) ? x:y)
#define min(x,y) (((x)<(y)) ? x:y)
#define FOR(a) for(int i=0;i<a;i++)
#define ender {return 0;}
#define tosasuretu(a) (a*(a+1)/2)
inline ll kaizyo(ll);
ll gcd(ll, ll);
ll combination(ll, ll);
int main(){
	int h,maxh=0, n;
	cin >> n;
	int count = 0;
	FOR(n) {
		cin >> h;
		if (maxh <= h) {
			count++;
			maxh = h;
		}
	}
	cout << count;
	return 0;
}


inline ll kaizyo(ll x) {
	ll ans = 1;
	for (int z = 0; z < x; z++) {
		ans *= (x - z);
	}
	return ans;
}
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
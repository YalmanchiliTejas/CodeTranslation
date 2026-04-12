#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi 3.14159265359
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }


int main() {
	ll N;
	cin >> N;
	cout << N * 800 - N / 15 * 200;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <iomanip>
#include <queue>
#include <string.h>
#include <bitset>

#define ll long long int
#define ld long double
#define rep(i,n) for(int i = 0;i < n;i++)
#define rep1(i,n) for(int i = 1;i < n;i++)
#define co(x) cout << x << endl
#define cosp(x) cout << x << " "
#define all(x) x.begin(),x.end()
#define allr(x) x.begin(),x.end(),greater<int>()
#define P pair<ll,ll>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1ll << 60
#define PI 3.14159265359

using namespace std;

int main(){
	int n;
	cin >> n;
	cout << n*800 - n/15 * 200 << endl;
	return 0;
}
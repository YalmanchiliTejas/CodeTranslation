//inlclude before define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
#include<assert.h>
#include<deque>
#include<iomanip>
#include<set>
#include<tuple>
#include<map>

using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef pair<int, int> P1;
typedef long long int ll;

//define
#define INF 1e9
#define NUM 1000000007
#define all(x) begin(x),end(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))

//function

/*ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}*/

/*ll lcm(ll a,ll b) {
	ll g = gcd(a, b);
	return a * (b / g);
}*/

/*int dig(int a) {
	int sum = 0;
	while (a) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}*/

int mem[10][10] = {};
int ans = 0;
int func (int a,int n,bool visited[]);

int main () {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	int a, b;
	rep (i, m) {
		cin >> a >> b;
		mem[a-1][b-1]++;
		mem[b-1][a-1]++;
	}
	
	bool visited[8];
	rep (i, n) visited[i] = false;
	visited[0] = true;
	func (0, n, visited);
	cout << ans << endl;
	
}

int func (int a,int n,bool visited[]) {
	bool judge = true;
	rep (i, n) {
		if (visited[i] == false) judge = false;
	}

	if (judge) {
		ans++;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (mem[a][i] == 0) continue;
		if (visited[i])continue;

		visited[i] = true;
		func (i, n, visited);
		visited[i] = false;
	}

	return 0;
}
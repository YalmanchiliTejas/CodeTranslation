#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <functional>
#include <cstring>

using namespace std;

template <class T> bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> bool chmin(T &a, const T &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

typedef pair<int, int> P;
#define mp make_pair
#define FOR(i, a, b) for(int (i)=a;(i)<(b);++(i))
#define rep(i, n)  FOR(i,0,n)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort((v).begin(), (v).end());					//小さい順
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());		//大きい順
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define all(c) (c).begin(),(c).end()
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define Print(p) cout<<(p)<<endl
#define F first
#define S second
#define pb push_back
#define mod 1000000007LL
#define INF 12345678901234567

const int maxn = 1e5 + 10;

int n;
string s;
bool check = false;
char ans[maxn]; //s;ひつじ w;狼

void dfs(int count) {
	if (s[count-1] == 'o'&&ans[count - 1] == 'S')ans[count] = ans[count - 2];
	else if (s[count-1] == 'x'&&ans[count - 1] == 'S')ans[count] = ans[count - 2]=='S'?'W':'S';
	else if (s[count-1] == 'o'&&ans[count - 1] == 'W')ans[count] = ans[count - 2]=='S'?'W':'S';
	else if (s[count-1] == 'x'&&ans[count - 1] == 'W')ans[count] = ans[count - 2];

	if (count == n)
	{
		char tmp;
		count = 1;
		if (s[count - 1] == 'o'&&ans[count - 1] == 'S')tmp = ans[count];
		else if (s[count - 1] == 'x'&&ans[count - 1] == 'S')tmp = ans[count] == 'S' ? 'W' : 'S';
		else if (s[count - 1] == 'o'&&ans[count - 1] == 'W')tmp = ans[count] == 'S' ? 'W' : 'S';
		else if (s[count - 1] == 'x'&&ans[count - 1] == 'W')tmp = ans[count];

		if (ans[n - 1] == tmp && ans[n] == ans[0]) check = true;
		else check = false;

		return;
	}

	count++;
	dfs(count);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	// your code is here
	cin >> n >> s;

	
	char animal[2];
	animal[0] = 'S';
	animal[1] = 'W';

	int test = 0;
	rep(i, 4)
	{
		ans[0] = animal[i / 2];
		ans[1] = animal[i % 2];
		dfs(2);
		if (check) break;
	}

	if (!check) cout << -1;
	else rep(i, n) cout << ans[i];
	cout << endl;
	// your code finished
	return 0;

}
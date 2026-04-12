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

typedef pair<int, int> P;
#define mp make_pair
#define FOR(i, a, b) for(int (i)=a;(i)<(b);++(i))
#define rep(i, n)  FOR(i,0,n)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort((v).begin(), (v).end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
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
#define INF 105000000000

const int maxn = 1e5 + 10;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int a, b, c; cin >> a >> b >> c;
	if ((10 * b + c) % 4 == 0) YES;
	else NO;

	return 0;
	
}
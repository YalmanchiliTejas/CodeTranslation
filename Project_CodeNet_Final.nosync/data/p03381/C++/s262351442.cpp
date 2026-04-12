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

#define mp make_pair
#define FOR(i, a, b) for(int (i)=a;(i)<(b);++(i))
#define rep(i, n)  FOR(i,0,n)
#define FFOR(i, a, b) for(int (i)=a;(i)>(b);--(i))
#define rrep(i,n) FFOR(i,0,n)
#define vsort(v) sort((v).begin(), (v).end());					//小さい順
#define rvsort(v) sort(v.begin(), v.end(),greater<>());		//大きい順
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define all(c) (c).begin(),(c).end()
#define ll long long
#define lb long double
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
#define INF 1234567890123456
typedef pair<int, int> P;
typedef pair<int, P> PP;

const int maxn =1e5 + 10;

//initialization here
//
int x[200005];
int y[200005];
//
//initialization finish


// your function is here
//

//
// your function finished

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	// your code is here
	//

	int n;cin >> n;
	rep(i,n) 
	{
		cin >> x[i];
		y[i] = x[i];
	}

	sort(y,y+n);

	int mean1 = y[n/2 - 1];
	int mean2 = y[n/2];

	rep(i,n)
	{
		if (x[i] <= mean1) Print(mean2);
		else Print(mean1);
	}


	//
	// your code finished


	return 0;
}
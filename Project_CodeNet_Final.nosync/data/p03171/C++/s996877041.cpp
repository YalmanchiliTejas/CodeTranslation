//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
#include<complex>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD =  (int)1e9 + 7;
const double EPS = 1e-9;

int N;
int A[3010];
int memo[3010][3010];

int DP(int l,int r)
{
	if(r<l)return 0;
	if(memo[l][r]!=INF)return memo[l][r];

	int p=(N^(r-l+1))&1;
	int res=0;
	if(p==0)
	{
		res=-INF;
		chmax(res,DP(l+1,r)+A[l]);
		chmax(res,DP(l,r-1)+A[r]);
	}
	else 
	{
		res=INF-1;
		chmin(res,DP(l+1,r)-A[l]);
		chmin(res,DP(l,r-1)-A[r]);
	}

	memo[l][r]=res;
	return memo[l][r];
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>N;
	rep(i,0,N)cin>>A[i];
	rep(i,0,3010)rep(j,0,3010)memo[i][j]=INF;

	cout<<DP(0,N-1)<<endl;
	
	return 0;
}
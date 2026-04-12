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

string K;
int D;
int DP[100010][105][2];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>K>>D;

	DP[0][0][1]=1;

	rep(i,0,SZ(K))rep(j,0,D)rep(k,0,2)
	{
		int kd=K[i]-'0';
		rep(d,0,10)
		{
			int ni=i+1,nj=(j+d)%D,nk=k;
			if(nk==1)
			{
				if(d>kd)continue;
				else if(d<kd)nk=0;
			}
			DP[ni][nj][nk]=(DP[ni][nj][nk]+DP[i][j][k])%MOD;
		}
	}

	cout<<(DP[SZ(K)][0][0]+DP[SZ(K)][0][1]-1+MOD)%MOD<<endl;
	
	return 0;
}
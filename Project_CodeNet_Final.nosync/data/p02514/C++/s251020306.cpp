#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iterator>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int INFTY=1<<29;

int getdist(pii a,pii b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int main()
{
	for(int w,h;cin>>w>>h,w|h;){
		pii start,goal;
		vector<vector<pii> > gems(1);
		rep(i,h) rep(j,w){
			string s; cin>>s;
			if(s=="S")
				start=mp(i,j);
			else if(s=="G")
				goal=mp(i,j);
			else if(isdigit(s[0])){
				int n=atoi(s.c_str());
				if(gems.size()<=n)
					gems.resize(n+1);
				gems[n].push_back(mp(i,j));
			}
		}
		gems[0].push_back(start);
		gems.push_back(vector<pii>(1,goal));
		
		vvi dp(gems.size());
		dp[0]=vi(1,0);
		repi(i,1,dp.size()){
			dp[i].assign(gems[i].size(),INFTY);
			rep(j,dp[i].size())
				rep(k,dp[i-1].size())
					dp[i][j]=min(dp[i][j],dp[i-1][k]+getdist(gems[i-1][k],gems[i][j]));
		}
		cout<<dp.back()[0]<<endl;
	}
	
	return 0;
}
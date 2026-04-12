#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
using ll=long long int;
using vi=vector<int>;
using vl=vector<ll>;
using vvi=vector<vi>;
using vvl=vector<ll>;
using vs=vector<string>;
constexpr int INF=1<<30;
constexpr ll INFL=1l<<60;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define RANGE(i,a,b) for(int i=(a);i<=(b);i++)
#define RANGER(i,a,b) for(int i=(b);i>=(a);i--)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)

#define EVALe 1

#ifdef EVAL
#define LOG(i) 0
#else
#define LOG(i) cerr<<#i<<": "<<i<<endl
#endif

void solve(){
	int N,M;
	cin>>N>>M;
	cout<<(N==M?"Yes":"No")<<endl;
}

int main(){
	solve();
	return 0;
}
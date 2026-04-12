#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define rep(i,n) for(int i = 0; i<n ; i++)
#define FOR(i,a,n) for(int i=a; i<n; i++)
#define REPSTR(i,s) for(int i=0; (s)[i]; i++)
#define REPITR(i,s) for(auto i=(s)begin(); i!=(s).end();i++)

#define RANGE(a,i,b) ((a)<=(i)&&(i)<=(b))

#define pb push_back
#define mp make_pair

#define ALL(a) (a).begin(), (a).end()

#define EXIST(s,x) ((s).find(x)!=(s).end())

#define SET(a,c) memset(a,c,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

#ifdef _DEBUG
#define DEBUG(x) cerr<<#x<<":"<<x<<endl
#else
#define DEBUG(x)
#endif

#define PRINTJOIN(x,n) rep(i,n){if(i)cout<<" ";cout<<x[i];}cout<<endl 

#define INF 1001001001
#define LLINF 1001001001001001001LL

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef stringstream SS;

#define PQ priority_queue

#define FST first
#define SEC second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//------------------HEAD---------------------

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	cout<<n*800-(n/15*200)<<endl;
	return 0;
}

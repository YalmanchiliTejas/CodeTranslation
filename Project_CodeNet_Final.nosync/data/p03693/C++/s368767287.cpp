//-------------
//include
//-------------
#include <map>
#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
#include <random>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
//-------------
//typedef
//-------------
typedef long long LL;
typedef  vector<int> VI;
typedef  pair<int, int> PII;
typedef  vector<int, int> VII;
typedef  map<string, int> MSI;
//-------------
//utillty
//-------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MK make_pair
#define PB push_back
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//-------------
//repetition
//-------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//-------------
//debug
//-------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define dumpl(x) REP(i,SZ(x))cerr<<i<<x<<"="<<x[i]<<endl;
const int MOD = 1000000007;
int main()
{
	int RGB=0,num;
	cin >> num;
	RGB += num * 100;
	cin >> num;
	RGB += num * 10;
	cin >> num;
	RGB += num * 1;
	RGB % 4 == 0 ? cout << "YES" << endl : cout << "NO" << endl;
#ifdef _DEBUG
	while(1);
#endif
	return 0;
}
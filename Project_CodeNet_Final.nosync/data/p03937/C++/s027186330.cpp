#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

string g[100];
int main(){
	int h, w;
	cin>>h>>w;
	rep(i, h) cin>>g[i];
	bool ok = true;
	if(g[0][0]!='#') ok = false;
	{
		int i = 0, j = 0;
		while(i<h && j<w){
			if(i==h-1 && j==w-1) break;
			if(i<h-1 && g[i+1][j]=='#') i++;
			else if(j<w-1 && g[i][j+1]=='#') j++;
			else break;
		}
		if(!(i==h-1 && j==w-1)) ok = false;
	}
	{
		int cnt = 0;
		rep(i, h) rep(j, w) if(g[i][j]=='#') cnt++;
		if(cnt!=h+w-1) ok = false;
	}
	cout<<(ok?"Possible":"Impossible")<<endl;
	return 0;
}

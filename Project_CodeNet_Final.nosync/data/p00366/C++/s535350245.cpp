#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define rep(i,a,n) for(ll i =(a);i<(n);++i)
#define urep(i,a,n) for(ll i = (a);i>=(n);--i)
#define all(x) (x).begin(),(x).end()
#define INF 1e18
const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
ll dx[4] = { 1,-1,0,0 };
ll dy[4] = { 0,0,1,-1 };
ll N,M,X,Y,A,B,C,Q,K,R,W,H;
string S,T;
ll ans;
ll x[1000000];
ll y[1000000];
ll a[1000000];
ll b[1000000];
ll c[1000000];
ll t[1000000];
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
struct Edge{
	ll to,cost;
	 Edge(int to, int cost) : to(to), cost(cost) {}
};
typedef vector<vector<Edge> > AdjList;
AdjList graph;
vector<ll> dist;
int main() {
	cin>>N;
	rep(i,0,N){
		cin>>t[i];
	}
	sort(t,t+N);
	vector<ll> v;
	rep(i,1,t[N-1]+1){
		if(t[N-1]%i==0)
			v.push_back(i);
	}
	ans=0;
	rep(i,0,N-1){
		ans+=*lower_bound(v.begin(),v.end(),t[i])-t[i];
	}
	cout<<ans<<endl;
	return 0;
}


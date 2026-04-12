#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100000;

int main() {
	ll n,x;cin>>n>>x;
	ll l[51];
	l[0]=1;
	for(int i=1;i<=n;i++) l[i]=2*l[i-1]+3;
	ll p[51];
	p[0]=1;
	for(int i=1;i<=n;i++) p[i]=2*p[i-1]+1;
	ll ans=0;
	for(int i=n;i>=0;i--){
		if(i==0) {ans+=1;break;}
		else if(x>(l[i]+1)/2) {ans+=p[i-1]+1;x-=(l[i]+1)/2;}
		else if(x==(l[i]+1)/2) {ans+=p[i-1]+1;break;}
		else if(x>1) x--;
		else if(x==1) break;
	}
	cout<<ans<<endl;
}

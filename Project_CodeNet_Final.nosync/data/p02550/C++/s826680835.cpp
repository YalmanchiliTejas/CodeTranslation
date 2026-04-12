#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <stack>
using namespace std;
#define ll long long
#define pb push_back
#define pp pair<long long,long long>
#define ppp pair<long long, pair<long long,long long> >
#define f first	
#define s second
#define pd pair<double,long long>
ll barr[100100],M=998244353;
void solveTestCase() {
	ll n,i,j,k,l,x,m;
	cin>>n>>x>>m;
	ll pre=x,sum=0;
	map<ll,ll> mp;
	mp[x]=1;
	for (i=1;i<=min(n,m);i++) {
		barr[i]=pre;
		//cout<<pre<<" ";
		sum+=pre;
		pre*=pre;
		pre%=m;
		if (mp.find(pre)!=mp.end())
			break;
		mp[pre]=i+1;
	}
	ll rem = n-i,res=0;
	for (j=mp[pre];j<=i;j++)
		res+=barr[j];
	ll len = i-mp[pre]+1;
	ll times = rem/len;
	ll mod = rem%len;
	sum+=(times*res);
	for (j=mp[pre];j<mp[pre]+mod;j++)
		sum+=barr[j];
	cout<<sum<<'\n';
}
int main() {
	ll t,n,i,j,k,l,m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll p;
	t=1;
	//cin>>t;
	for (ll T=1;T<=t;T++) {
		solveTestCase();
	}
	return 0;
}
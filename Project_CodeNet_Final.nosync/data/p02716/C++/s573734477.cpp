//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define fo(i,n) for(int i=0;i<(n);i++)
#define inp(a) int a;cin>>a;
#define inpa(a,n)vector<int> a(n);fo(i,n)cin>>a[i];
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
using namespace std;
#define int ll
// #define MAX 20
#define INF (int)1e18
 
template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.F<<','<< P.S<<')';}
 
vector<int> a;
int n;
map<pair<int,int>,int> done;
 
 
int f(int l,int r,int left)
{
	if(left==0)
		return 0;
	if(r-l+1<left*2-1 || r<l)
		return -INF;
	if(done.find({l,left})!=done.end())
		return done[{l,left}];
	return done[{l,left}]=max(a[l]+f(l+2,r,left-1), f(l+1,r,left));
}
 
 
signed main()
{
	fio
	cin>>n;
	a.resize(n);
	fo(i,n)	
		cin>>a[i];
	cout<<f(0,n-1,n/2)<<'\n';
	printclock;
}
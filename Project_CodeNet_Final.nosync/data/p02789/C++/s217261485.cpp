//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pf pop_front
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


signed main()
{
	fio
	inp(n) inp(m)
	if(n==m)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	printclock;
}
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}
template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}


signed main()
{
	speed
	int n,m;cin>>n>>m;
	if(n==m){cout<<"Yes\n";}
	else{cout<<"No\n";}
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <fstream>
#include <queue>
#include <iomanip>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#define fast ios_base::sync_with_stdio(false)
#define mxn (ll)1e5
#define mod (ll)(1e9+7)
#define mod1 (ll)(998244353)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vvi vector<vi >
#define pi pair<ll,ll>
#define vvpi vector<vector<pi > >
#define vpi vector<pi >
#define vppi vector<pair<ll,pi > >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fs first
#define se second
#define crz(v,n) v.clear(),v.resize(n+1,0)
#define print(v) for(ll it=0;it<v.size();it++) cout<<v[it]<<" ";cout<<endl
#define printp(v) for(ll it=0;it<v.size();it++) cout<<v[it].first<<" "<<v[it].second<<endl
using namespace std;
int main(){
	int i,j,n;ll s=0;cin>>n;vi v(n);for(i=0;i<n;i++) cin>>v[i],s+=v[i];
	vvpi d(n+1,vpi(n+1));for(i=1;i<=n;i++) d[i][i].fs=v[i-1],d[i][i].se=0;
	for(i=1;i<n;i++){
		for(j=1;j<=n-i;j++){
			int a=j,b=i+j;
			d[a][b].fs=max(v[a-1]+d[a+1][b].se,v[b-1]+d[a][b-1].se);
			if(v[a-1]+d[a+1][b].se>v[b-1]+d[a][b-1].se) d[a][b].se=d[a+1][b].fs; else d[a][b].se=d[a][b-1].fs;
		}
	}cout<<2*d[1][n].fs-s<<endl;
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++) cout<<d[i][j].fs<<" "<<d[i][j].se<<"   ";cout<<endl;
//	}
}

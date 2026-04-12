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
ll d[mxn+5][105][2];
int main(){
	int n,i,j,k,e,dd;string s;cin>>s>>dd;n=s.size();
	d[0][0][1]=1;
	for(i=0;i<n;i++){
		for(j=0;j<dd;j++){
			for(e=0;e<2;e++){
				int x=(e?s[i]-48:9);
				for(k=0;k+e<=x;k++) d[i+1][(j+k)%dd][0]=(d[i+1][(j+k)%dd][0]+d[i][j][e])%mod;
				if(e) d[i+1][(j+x)%dd][1]=(d[i+1][(j+x)%dd][1]+d[i][j][e])%mod;
			}
		}
	}cout<<(d[n][0][0]+d[n][0][1]-1+mod)%mod<<endl;
}

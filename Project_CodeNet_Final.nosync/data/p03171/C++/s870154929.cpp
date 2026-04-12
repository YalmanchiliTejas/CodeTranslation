#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = ((B)-1); I >= (A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
#define pri(a) cout << (a) << endl



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n+1,0),sum(n+1,0);
	FOR(i,1,n+1)cin>>a[i];
	ll dpf[n+1][n+1]={},dps[n+1][n+1]={};
	FOR(i,1,n+1)dpf[i][i]=a[i];
	FOR(i,1,n+1)sum[i]=sum[i-1]+a[i];
	FOR(i,1,n+1){
		for(int j=0;i+j<=n;j++){
			dpf[j][i+j]=max(dps[j+1][i+j]+a[j],dps[j][i+j-1]+a[i+j]);
			dps[j][i+j] = sum[i+j]-sum[j-1] - dpf[j][i+j];
		}
	}
	cout << dpf[1][n]-dps[1][n] << endl;
}

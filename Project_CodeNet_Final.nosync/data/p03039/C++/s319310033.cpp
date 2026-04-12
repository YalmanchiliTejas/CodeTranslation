#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
const int MAXN=200005;
const int MOD=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define fst first
#define snd second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())

int N,Q;
map<int,int>M;
ll modpow(ll base, ll expo){
	ll res=1;
	while(expo>0){
		if(expo&1)res=res*base%MOD;
		base=base*base%MOD;
		expo>>=1;
	}
	return res;
}
ll nCr(ll n, ll r){
	ll res=1;
	FOR(i,n-r+1,n)res=res*i%MOD;
	ll d=1;
	FOR(i,1,r)d=d*i%MOD;
	return res*modpow(d,MOD-2)%MOD;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll N,M,K;
	cin>>N>>M>>K;
	cout<<(N*N%MOD*(M*(M*(M+1)/2)%MOD-M*(M+1)%MOD*(2*M+1)%MOD*modpow(6,MOD-2)%MOD+MOD)%MOD+M*M%MOD*(N*(N*(N+1)/2)%MOD-N*(N+1)%MOD*(2*N+1)%MOD*modpow(6,MOD-2)%MOD+MOD)%MOD)%MOD*nCr(N*M-2,K-2)%MOD<<"\n";
}
/*
1 3
#.#


2 3
#.#
..#

3 3
##.
#.#
..#

3
2 5
6 1
3 7
Ans:6

4
3 7
2 9
8 16
10 8
Ans:9
*/

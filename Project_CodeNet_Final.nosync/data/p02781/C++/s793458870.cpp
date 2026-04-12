
// Problem : 
// 			E - Almost Everywhere Zero
// 			Editorial
// 		
// Contest : AtCoder - AtCoder Beginner Contest 154
// URL : https://atcoder.jp/contests/abc154/tasks/abc154_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,b,a) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
 
#define bug(x) cout<<#x<<"="<<x<<endl; 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ld pii=3.14159265359; 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001; //check the limits, dummy
string str;
int K;
int N;
map<pi,ll> m1,m2;
ll calc(bool eq,int k,int level) 
{
	if(k==0)
		return 1;
	if(level==N)//?
		return 0;//?
	if(str[level]=='0')
	{
		if(eq)
			return calc(true,k,level+1);
		else
			return 9*calc(false,k-1,level+1)+calc(false,k,level+1);
	}
	
	if(eq)
	{
		if(m1.find({k,level})!=m1.end())
			return m1[{k,level}];
		return m1[{k,level}]=calc(true,k-1,level+1)+calc(false,k,level+1)+(str[level]-'0'-1)*calc(false,k-1,level+1);
		// return m1[{k,level}];
	}
	else
	{
		if(m2.find({k,level})!=m2.end())
			return m2[{k,level}];
		return m2[{k,level}]=9*calc(false,k-1,level+1)+calc(false,k,level+1);
	}
}
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);    
	cin>>str;
	cin>>K;
	N=sz(str);
	cout<<calc(true,K,0);
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
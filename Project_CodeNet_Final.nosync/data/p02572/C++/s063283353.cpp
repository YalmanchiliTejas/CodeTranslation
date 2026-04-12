//	@Author : Gaurang_Kothiya

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <bitset>
#include <cstdint>
#include <initializer_list>
 
using namespace std;
using namespace __gnu_pbds;  

#define data_set(type) tree<type,null_type,less<type>,rb_tree_tag,tree_order_statistics_node_update>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define ld long double
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fe(x,v)   for(auto &x :v)
#define nf(i,x,n) for(int i=n;i>=x;i--)
#define all(a)   a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define ook(num) order_of_key(num)
#define fbo(num) find_by_order(num)
#define gcd(a,b) __gcd(a,b)
#define bits(n) __builtin_popcountll(n)
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define RE rend()
#define RB rbegin()
#define B begin()
#define E end()
#define acc(v, x) accumulate(all(v), x)
#define p(a,b) pair<a,b>
#define F first
#define S second
#define sz size()
#define v(x) vector<x>
#define m(a,b) map<a,b>
#define u_m(a,b) unordered_map<a,b>
#define mm(a,b) multimap<a,b>
#define s(a) set<a>
#define us(a) unordered_set<a>
#define ms(a) multiset<a>
#define maxy __LONG_LONG_MAX__
#define miny INT_MIN
#define PI 3.14159265358979323846

const int inf= 1e9 +1;
const int inf64= 1e18 -1;
const int MOD= 1e9 +7;
const int MOD2= 998244353;



void Solve()
{
	int n;
	cin>>n;
	int a[n];
	f(i,0,n-1)
	{
		cin>>a[i];
	}
	int suf[n]={0};
	suf[n-1]=a[n-1];
	nf(i,0,n-2) suf[i]= (suf[i+1]+a[i]);
	
	int ans=0;
	
	f(i,0,n-2)
	{
		ans= (ans + (a[i]* (suf[i+1]%MOD))  )%MOD;
	}
	cout<<ans;
}
 
signed main() 
{
	//speed		

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);	

	int q=1;
	//cin>>q;
	
	while(q--)
	Solve();
		
	return 0;
} 
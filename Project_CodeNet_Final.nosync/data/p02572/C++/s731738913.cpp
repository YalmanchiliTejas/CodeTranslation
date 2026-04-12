/*
  
  Author: Arnab Sinha
	
  ███████╗██╗  ██╗███████╗██████╗         ██╗      ██████╗  ██████╗██╗  ██╗███████╗██████╗  █████╗  █████╗ 
  ██╔════╝██║  ██║██╔════╝██╔══██╗        ██║     ██╔═══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗██╔══██╗██╔══██╗
  ███████╗███████║█████╗  ██████╔╝        ██║     ██║   ██║██║     █████╔╝ █████╗  ██║  ██║╚██████║╚██████║
  ╚════ █║██╔══██║██╔══╝  ██╔══██╗        ██║     ██║   ██║██║     ██╔═██╗ ██╔══╝  ██║  ██║ ╚═══██║ ╚═══██║
  ███████║██║  ██║███████╗██║  ██║███████╗███████╗╚██████╔╝╚██████╗██║  ██╗███████╗██████╔╝ █████╔╝ █████╔╝
  ╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝╚══════╝╚═════╝  ╚════╝  ╚════╝                                                                                                        
*/

#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define li long long int
#define ld long long double
#define all(v) v.begin(),v.end()
#define sort(a) sort(all(a))
#define rev(a) reverse(all(a))
#define pb push_back
#define INF 1e18+10
#define MINF -1e18-10
#define rep(i,a,b) for(li i=a;i<b;i++)
#define vli vector<li>
#define MAXN 1e5+10
const li mod = 1e9+7;
using namespace std;

li power(li a, li b) { a%=mod; li ret = 1; while(b){ if(b&1) ret*=a; a*=a;; if(ret>=mod) ret%=mod; if(a>=mod) a%=mod; b>>=1; } return ret; }

template <class T> void read(T& x){
	cin>>x;
}

template <class T, class... U> void read(T& x, U&... u){
	read(x);
	read(u...);
}

template <class A> void read(vector<A>& v){
	for(auto &it:v)
		read(it);
}

template <class A> void print(A x){
	cout<<x;
}

template <class A> void printl(A x){
	cout<<x<<endl;
}

template <class A> void print(vector<A>& v)
{
	for(auto &it:v){
		print(it);
		cout<<' ';
	}
	cout<<'\n';
}

void solve()
{
	li n;
	cin>>n;

	vli v(n);
	read(v);

	vli pref(n+1,0);

	pref[n] = 0;
	for(li i=n-1;i>=1;i--)
	{
		pref[i] = (pref[i+1] + v[i])%mod;
	}

	li sum = 0;

	for(li i=0;i<n-1;i++)
	{
		sum = (sum + (v[i]*pref[i+1])%mod)%mod;
	}

	cout<<sum<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	IOS;

	solve();

	return 0;
}
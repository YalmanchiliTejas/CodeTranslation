#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define sz(a) (int)(a.size())
#define pb push_back
#define all(c) c.begin(),c.end()
#define tr(it,a,c) for(auto it=c.begin()+a;it!=c.end();it++)
#define fr(i,a,n)	for(int i=a;i<n;i++)
#define present(c,x) (c.find(x)!=c.end()) //for set/map etc.
#define cpresent(c,x) (find(all(c),x)!=c.end())
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vp;
int N=100001;
int mod=1e9+7;


int min(int a,int b){if(a<b) return a; else return b;}
int max(int a,int b){if(a>b) return a; else return b;}
int power(int a,int b){int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int p, int q){if(p%q==0) return q; else{return gcd(q,p%q);}} 
bool comp(int a, int b) 
{ 
    return (a > b); 
}

bool comp1(pi a, pi b)
{
	if(a.first==b.first)return a.second<b.second;
	else return a.first>b.first;
}

template<typename T> 
istream& operator>>(istream& in, vector<T>& v)
{
	for (T& x : v) in >> x; return in;
}

template<typename T> 
ostream& operator<<(ostream& out, vector<T>& v)
{
	for (T& x : v) out << x<<" "; return out;
}

// template<typename T>
int sum1(vector<int>& v)
{
	int sum=0;
	// for(auto x: v)sum+=x;
	fr(i,0,v.size())sum+=v[i];
	return sum;
}





 void solve()
{
	int n;
	cin>>n;
	if(n>=30)cout<<"Yes";
	else cout<<"No";

}

signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	// int t;
	// cin>>t;
	// while(t--)
	// {
	// 	solve();
	// 	cout<<endl;
	// }
	solve();
	return 0;	
}
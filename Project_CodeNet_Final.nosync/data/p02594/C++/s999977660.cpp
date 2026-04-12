#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define M 1000000007
#define ll long long int
#define F first
#define S second
#define INF (int)1000000000
const int N = 1e5+5;
#define maax(a,b,c) max((int)a,max((int)b,(int)c))
#define miin(a,b,c) min((int)a,min((int)b,(int)c))
#define mp make_pair
#define int long long
#define all(a) a.begin(),a.end()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define inf (long long) 1e18
#define vl vector<ll>
#define sz(a) (ll)a.size()
#define I insert
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(i,m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define fre(i,m, n) for (int i = (int)(n); i <= (int)(m); i--)
#define rall(x) (x).rbegin(), (x).rend()
#define TIME    cerr << "\nTime elapsed: " << setprecision(5) <<1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
//void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}//
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef pair<int, int> PII;
int aa[100005];
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
bool is_prime(int n)
{
	if(n==1) return true;
	int g=sqrt(n);
	for(int i=2;i<=g;i++)
	{
		if(n%i==0) return true;
	}
	return false;
}
int b[N];
int check(int n)
{
	if(b[n]!=0) return b[n];
	int h=0,y=n;
	while(n)
	{
		h++,n/=10;
	}
	b[y]=h;
	return h;
}
int a[100000000];
int aha(int n)
{int y=0;
    while(n%10!=0) n/=10;
	while(n)
	{
		y+=n%10;n/=10;
	}
	return y;
}
int lol(int n)
{
	int y=0;
	fr(i,1,INF)
	{
		if(a[i]!=0) y=a[i];
		else 
		{
			if(i%10==0) y=aha(i);
			else y++;
		}
		a[i]=y;//debug(i,y);
		if(y==n) return i; 
	}
	return 0;
}

int poo()
{
    int x,y,z;cin>>x>>y>>z;int a,b;cin>>a>>b;
    if((2*x)<min(y,z))
    {
    	cout<<0<<"\n";return 0;
	}
	int y1=max(y,z);
	cout<<(y1-x)+1<<"\n";
	return 0;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;//int y=aha(28000);cout<<y<<" ";
//    while(t--) poo();
    (t<30)?cout<<"No\n":cout<<"Yes";
    return 0;	
} 
//no of pairs of an array => ((n)*(n+1))/2;
//(1,2) (1,3) (1,4) (2,3) (2.4) (3,4)
//i>>j = i/(2^j)
//set-> all elements are unique and sorted ^_^?

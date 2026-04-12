/* 
  ╔╗         ╔╗              ╔═══╗                                  
  ║║        ╔╝╚╗             ║╔═╗║                                  
  ║║╔╗╔╗╔══╗╚╗╔╝    ╔══╗     ║╚═╝║╔═╗╔══╗╔══╗╔═╗╔══╗ ╔╗╔╗╔╗╔╗╔══╗╔═╗
╔╗║║║║║║║══╣ ║║     ╚ ╗║     ║╔══╝║╔╝║╔╗║║╔╗║║╔╝╚ ╗║ ║╚╝║║╚╝║║╔╗║║╔╝
║╚╝║║╚╝║╠══║ ║╚╗    ║╚╝╚╗    ║║   ║║ ║╚╝║║╚╝║║║ ║╚╝╚╗║║║║║║║║║║═╣║║ 
╚══╝╚══╝╚══╝ ╚═╝    ╚═══╝    ╚╝   ╚╝ ╚══╝╚═╗║╚╝ ╚═══╝╚╩╩╝╚╩╩╝╚══╝╚╝ 
                                         ╔═╝║                       
                                         ╚══╝                       */


//Header files
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

/*-----------------------------------------------Debug Template Start-----------------------------------------------*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
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

/*-----------------------------------------------Debug Template End-----------------------------------------------*/

//Short data-types declaration
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vector<int> > vii;  
typedef vector<vector<long long> >vll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vbb;

//Macros
#define MK make_pair
#define EB emplace_back
#define PB push_back
#define F first
#define S second
#define rep(i,start,end) for(int i=(int)start;i<(int)end;i++)
#define repr(i,start,end) for(int i=(int)start;i>(int)end;i--)
#define all(x) (x).begin(), (x).end()

//Constants
const int mod = 1e9+7;

//Some useful functions
int binpow(int num,int pow);
inline int mul(int a,int b) {return (a*1ll*b)%mod;}
inline int add(int a,int b) {return (a+0ll+b)%mod;}
inline int sub(int a,int b) {return ((a+0ll-b)%mod+mod)%mod; }
inline int inv(int num)
{
	return binpow(num,mod-2);
}
/*------------------------------------------------------Code Starts------------------------------------------------------*/
inline void solve()
{
	int n;
	cin>>n;
	vi a(n);
	for(int &i:a) cin>>i;
	int sum=0;
	int indi=0;
	rep(i,0,n)
	{
		sum=add(sum,a[i]);
		indi=add(indi,mul(a[i],a[i]));
	}
	sum=mul(sum,sum);
	int ans=mul(sub(sum,indi),inv(2));
	cout<<ans<<'\n';
}

int main()
{
	auto start = high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	cerr<<duration.count()<<" microseconds\n";
	return 0;
}
/*------------------------------------------------------Code ends------------------------------------------------------*/
int binpow(int num,int pow)
{
	if(pow==0)
		return 1;
	int val=binpow(num,pow/2);
	val=mul(val,val);
	if(pow&1) val=mul(num,val);
	return val;
}


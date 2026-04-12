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
#ifndef ONLINE_JUDGE
#include<Personal/debug.h>
#else
#define debug(x...)
#endif

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
ll binpow(ll num,ll pow);
inline int mul(int a,int b) {return (a*1ll*b)%mod;}
inline int add(int a,int b) {return (a+0ll+b)%mod;}
inline int sub(int a,int b) {return ((a+0ll-b)%mod+mod)%mod; }
/*------------------------------------------------------Code Starts------------------------------------------------------*/
inline void solve()
{
	int x;
	cin>>x;
	if(x>=30) cout<<"Yes\n";
	else cout<<"No\n";
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
ll binpow(ll num,ll pow)
{
	if(pow==0)
		return 1;
	ll val=binpow(num,pow/2);
	val*=val;
	if(pow&1) val*=num;
	return val;
}


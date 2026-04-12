#pragma GCC Optimize("Ofast")
#pragma GCC Optimize "trapv"
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 

using namespace std;
//using namespace boost::multiprecision; 

#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define TC int t; cin >> t; while(t--)
#define li long int
#define ll long long
#define ull unsigned long long 
#define Vec(x) vector <x>
#define Pai(x,y) pair <x,y>
#define Map(x,y) map <x,y>
#define UMap(x,y) unordered_map <x,y>
#define Set(x) set <x>
#define Sta(x) stack <x>
#define Qu(x) queue <x>
#define DQ(x) deque(x)
#define PriorQ(x)	priority_queue <x>
#define bg begin()
#define ed end()
#define sz size()
#define ct(x) count(x)
#define len length()
#define F first
#define S second
#define Makep make_pair
#define ins(x) insert(x)
#define ers(x) erase(x)
#define endl "\n";
#define MOD 1000000007
#define PI 2*acos(0.0)
#define clr() clear()
#define fori0(n) for(int i=0;i<n;i++)
#define foriab(a,b) for(int i=a;i<b;i++)
#define mem0(x) memset(x,0,sizeof(x))
#define mem1(x) memset(x,1,sizeof(x))
#define autoit(x) for(auto it=x.beg;it!=x.ed;it++)
#define count0(x) __builtin_popcount(x)
#define ret return 
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

const ll Inf=1e9+5;

ll a[100005],freq[1000006],mx=INT_MIN;

namespace funset{
bool checkvow(char x){
	return ((0x208222)>>(x&(0x1f)))&1;
	}
ll highpow2(ll x){
	return (x&~(x-1));
	}
bool chk2(ll x){
		return (x&(x-1));
	}	
}

using namespace funset;

ll n, w;
ll wei[101],val[101],dp[1001][10001];

string s;


void solve(){
	ll x;
	cin >> x;
	if(x>=30){
		cout << "Yes" << endl;
		return ;
	}
	cout << "No" << endl;
}

int main(){
	auto beg=clock();
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif	
	FAST
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    solve();
	auto ted=clock();
	#ifndef ONLINE_JUDGE
	cout << (double)(ted-beg)/CLOCKS_PER_SEC << endl;
	#endif
	ret 0;
}
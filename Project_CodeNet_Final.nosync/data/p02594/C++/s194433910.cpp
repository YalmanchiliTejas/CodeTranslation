#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define all(x) (x).begin(),(x).end()
#define S(x) (int)(x).size()
#define L(x) (int)(x).length()
#define debug(x) cerr << #x << " " << x << endl;
#define debug_p(x) cerr << #x << " [" << x.fi << " " << x.se << "]"<<endl;
#define debug_v(x) {cerr << #x << " "; for (auto ioi : x) cerr << ioi << " "; cerr << endl;}
#define debug_vp(x) {cerr << #x << " "; for (auto ioi : x) cerr << '[' << ioi.fi << " " << ioi.se << ']'; cerr << endl;}
#define debug_v_v(x) {cerr << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cerr << ioi2 << " "; cerr << '\n';} cerr << "*/" << #x << endl;}
#define gen_clock(x) ll x = clock(); cerr << "Clock " << #x << " created" << endl;
#define check_clock(x) cerr << "Time spent in " << #x << ": " << (double)(clock() - x)/CLOCKS_PER_SEC << endl; x = clock();
#define reset_clock(x) x = clock()
 
const int mod = 1e9+7;
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
 
void solve()
{
	ll x;
	cin>>x;
	if(x>=30)
	cout<<"Yes";
	else
	cout<<"No";
}
 
int main()
{
	IOS
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}

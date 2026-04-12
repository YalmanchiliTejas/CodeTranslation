#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define pb                      push_back
#define MOD                     1000000007
#define inf                     3e18
#define ld                      long double
//#define mp                      make_pair
#define vpll                    vector<pair<ll,ll>>
#define sll                     set<ll>
#define vll                     vector<ll>
#define vld                     vector<ld>
#define vvll                    vector<vector<ll>>
#define vvld                    vector<vector<ld>>
#define pll                     pair<ll,ll>
#define vvpll                   vector<vector<pair<ll,ll>>>
#define pqll                    priority_queue<ll>
#define mll                     map<ll,ll>
#define mlc                     map<ll,char>
#define um                      unordered_map
#define umll                    um<ll,ll>
#define umlc                    um<ll,char>
#define umcl                    um<char,ll>
#define all(x)                  x.begin(),x.end()
#define fi                      first
#define se                      second
#define test                    ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO                  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << " "<< name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

void inp_out()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

int main()
{
	fastIO
	//inp_out();
	string s;
	cin>>s;
	ll a=count(all(s),'A');
	ll b=count(all(s),'B');
	if((a==0)||(b==0))
	{
		cout<<"No";
	}
	else
	{
		cout<<"Yes";
	}
	return 0;
}


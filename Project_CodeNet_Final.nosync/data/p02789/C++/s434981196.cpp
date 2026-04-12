#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define loop(i,s,e) for(ll i=s; i<e; i++)
#define endl '\n'
#define vll vector<ll>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define N 100001
#define pb push_back
#define INF LLONG_MAX
#define inf INT_MAX
#define minusinf INT_MIN

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

void alpha(){

	ll n, m;
	cin>>n>>m;

	if(n==m) cout<<"Yes";
	else cout<<"No";

	
	return;

}

int main(){

	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif

    ll t=1;
	//cin>>t;

  	while(t--) alpha();

	return 0;

}
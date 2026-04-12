/* Author VS_CODE */

#include<bits/stdc++.h>
#define int long long
#define TCI int t;cin>>t;while(t--)
#define run(n) for(int i=1;i<=n;i++)
#define cinl(n) for(int i=0;i<n;i++)
#define ln "\n"
#define vpair vector< pair <int , int > >
#define fr first
#define sc second
#define pb emplace_back
#define vll vector<int>
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Point complex<int>
using namespace std;

void online()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/* CODE STARTS HERE */

template<typename T>
void debug(T x)
{
	cout<<x<<ln;
}

const int N = 1e5;

void solve()
{
	int n;
	cin>>n;
	if(n>=30)
		cout<<"Yes";
	else
		cout<<"No";
}


/* CODE ENDS HERE AND MAIN STARTS */

int32_t main()
{

	online();
	//TCI
	solve();
}
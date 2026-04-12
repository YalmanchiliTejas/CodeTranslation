#include<bits/stdc++.h>
using namespace std;
#define debug(x)        cout<<#x<<" :"<<x<<endl;
#define ff              first
#define ar              array
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,n)          for(int i=0;i<n;i++)
#define MOD             1000000007
#define pi              3.14159265
#define umii            unordered_map<int,int>
#define umci            unordered_map<char,int>
#define umsi            unordered_map<string,int>

void k_007()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("ip1.txt", "r", stdin);
	freopen("op1.txt", "w", stdout);
#endif
}
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b);
int gcd(int a, int b) ;
int prime(int n);
int power(int x, int y);
int lcm(int a, int b);
int32_t main()
{
	k_007();
	int n, m;
	cin >> n >> m;
	if (n == m) cout << "Yes" << endl;
	else cout << "No" << endl;
}


bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int prime(int n) {
	int flag = 1;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {flag = 0; break;}
	}
	return flag;
}
int power(int x, int y)
{
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return ((power(x, y / 2) % MOD) * ( power(x, y / 2) % MOD)) % MOD;
	else
		return ((x % MOD) * (power(x, y / 2) % MOD) * (power(x, y / 2) % MOD)) % MOD;
}
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}
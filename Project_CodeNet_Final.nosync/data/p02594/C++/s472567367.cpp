/*
Dont BLUNDER
*/
#include<bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


 */
//#define d long double
#define int long long
#define pii pair<int,int>
#define pb push_back
#define endl '\n'
#define pi acos(-1)

#define init(x,a) memset(x,a,sizeof(x))
#define all(c) c.begin(),c.end()
int const mod1 = 998244353;
int const mod = 1000000007;
#define l first
#define r second
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring ( int number ) {stringstream ss; ss << number; return ss.str();}
#define out(x) cout<<#x<<" = "<<" "<<x<<"\n";
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define haha ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// * Using PBDS *
/*typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
               os; */



int modexp(int x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n & 1) {
		return (modexp((x * x) % mod, n / 2) % mod * x % mod) % mod;
	}
	else {
		return (modexp((x * x) % mod, n / 2) % mod);
	}
}

int modinv(int n)
{
	return modexp(n, mod - 2);
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}





signed main()
{
	haha
#ifndef ONLINE_JUDGE

	freopen("inp.txt", "r", stdin);

	freopen("out.txt", "w", stdout);
#endif
	int x;
	cin>>x;
	if(x>=30)
		cout<<"Yes";
	else
		cout<<"No";






}
/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define int             long long
#define float           double
#define ms(s, n) 		memset(s, n, sizeof(s))
#define dip(type,var)   type var; cin>>var;
#define dipi(x)         int x; cin>>x;
#define dipi2(x,y)      int x,y; cin>>x>>y;
#define w(x)            int x; cin>>x; while(x--)
#define mka(type,arr,n) type *arr=new type[n];
#define fo(i,n)         for(int i=0;i<n;i++)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define inf             1e18
#define pi              3.141592653589793238
#define endl            "\n"
#define f               first
#define s               second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >

void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {
	c_p_c();
	dipi(x);
	if (x >= 30)
		cout << "Yes";
	else
		cout << "No";
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

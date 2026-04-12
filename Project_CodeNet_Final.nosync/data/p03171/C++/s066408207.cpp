#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
 
#define ff                  first
#define ss                  second
#define endl                "\n"
#define loop(i,s,e)         for(int i=s;i<e;i++)
#define int                 long long
#define vi                  vector<int> 
#define S(v)                sort(v.begin(),v.end())
#define RS(v)               sort(v.rbegin(),v.rend())
#define R(v)                reverse(v.begin(),v.end())
#define mxpq(T)             priority_queue <T>
#define mnpq(T)             priority_queue<T,vector<T>,greater<T>>
#define prv(v)              for(auto &x : v)cout << x << " ";
#define piirv(v)            for(auto &x : v)cout << x.ff << " " << x.ss << endl;
#define prvv(v)             for(auto &x : v)for(auto &y : x.ss)cout << y << " ";
#define mp                  make_pair
#define pii                 pair<int,int>
#define mset(a,f)           memset(a , f , sizeof(a))
#define pb                  push_back
#define inf                 INT_MAX
#define INF                 LLONG_MAX
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
 
const int N = 2e6 + 6;
const int M = 1e9+7;
int A[N];
int dp[3003][3002][2];
int n , m;

int alpha(int i , int j , int ok)
{
	if(i > j)return 0;
	int &abs = dp[i][j][ok];
	if(abs != -1)return abs;
	int ans = 0;
	if(!ok)
	{
		int a1 = A[i] + alpha(i+1 ,  j , 1-ok);
		int a2 = A[j] + alpha(i , j-1 , 1-ok);
		ans = max(a1 , a2);
	}
	else 
	{
		int a1 = alpha(i+1 ,  j , 1-ok) - A[i];
		int a2 = alpha(i , j-1 , 1-ok) - A[j];
		ans = min(a1 , a2);
	}
	return abs = ans;
}

void solve()
{
	cin >> n;

	loop(i,0,n)cin >> A[i];

	mset(dp , -1);

	int ans = alpha(0 , n-1 , 0);

	cout << ans;
}			
 
int32_t main()
{
 
cout<<fixed<<setprecision(16);
 
ios_base:: sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
 	
 
 	int t = 1;
 	// cin >> t;
 	while(t--)solve();
  
}
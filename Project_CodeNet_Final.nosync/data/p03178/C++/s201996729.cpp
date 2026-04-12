#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
 
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 
#define int long long
#define MOD 1000000007
#define what_is(x) cerr << #x << " is " << x << endl;
#define loop(i,a,n) for(int i=a;i<n;i++)
 
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, szof(x))
#define sortall(x) sort(aint(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<int, int> pt;
#define N 2 
int getMin(int x, int y) { return (x<y)? x: y; } 

signed main() {
 
	fastio();
	//#define LOCAL_DEFINE
	#ifdef LOCAL_DEFINE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	string n;
	int k;
	cin>>n;
	cin>>k;
	vector<int> dp(k,0),dp1(k,0);
	dp1[0]=1;
	int res=0;
	for(int i=0;i<n.length();i++)
	{
		vector<int> new_dp(k,0),new1_dp(k,0);
		for(int a=0;a<=9;a++)
		{
			for(int j=0;j<k;j++)
			{
				new_dp[(a+j)%k]+=dp[j];
				new_dp[(a+j)%k]%=MOD;
				if(a<(n[i]-'0'))
					new_dp[(a+j)%k]+=dp1[j],new_dp[(a+j)%k]%=MOD;
			}
		}
		res+=(n[i]-'0');
		res%=k;
		new1_dp[res]=1;
		dp=new_dp;
		dp1=new1_dp;
		//cout<<dp[0]<<" "<<dp1[0]<<endl;
	}
	if(res==0)
		dp[0]+=1;
	cout<<(dp[0]-1+MOD)%MOD;
	return 0;

 }

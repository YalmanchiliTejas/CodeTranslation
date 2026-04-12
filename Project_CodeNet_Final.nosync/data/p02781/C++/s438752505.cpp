#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
using namespace         std;
#define                 int long long
#define                 double long double
#define                 pb push_back
#define                 mp make_pair
#define st(arr,a)       memset(arr,a,sizeof arr)
#define                 nl cout<<'\n'
#define bitcount(x)     __builtin_popcountll(x)
const int MOD = 1000000007ll;
#define forn(i,a,b)     for(int i=a;i<=b;i++)
#define rfor(i,a,b)     for(int i=a;i>=b;i--)
#define all(x)          x.begin() , x.end()
#define pi pair<int,int>
#define X first
#define Y second
#define N 1014159
#define  vi vector<int>
#define  v  vector
#define die exit(0)
#define alln(arr) arr+1 , arr+1+n
using namespace __gnu_pbds;  
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update> oset; 

int n,m,k,arr[N];
string s;

int dp[200][5][3];

int get(int idx,int tot,int tight)
{
	if(tot>k)return 0;
	if(idx == -1)
	{
		if(tot!=k)return 0;
		return 1;
	}
	int&ans = dp[idx][tot][tight];
	if(ans!=-1)return ans;
	ans = 0;


	if(tight == 1)
	{
		int p = s[idx]-'0';
		if(p == 0)
		{
			ans = get(idx-1,tot,tight);
		}
		else
		{
			ans = get(idx-1,tot,0) + (p-1)*get(idx-1,tot+1,0) + get(idx-1,tot+1,1); 
		}
	}	
	else
	{
		int p = s[idx]-'0';
		ans = get(idx-1,tot,0)+9*get(idx-1,tot+1,0);

	}
	return ans;
}


void solve()
{
	st(dp,-1);
    cin>>s>>k;
    n = s.size();
    reverse(all(s));
    cout<<get(n-1,0,1);




}


signed main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t = 1;
    //cin>>t;
    forn(i,1,t)
    {
        solve();
        nl;
    }



    return 0;

}

//       clang++ c.cpp ; ./a.out < a.txt ;  
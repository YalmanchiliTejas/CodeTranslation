#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define append push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pb push_back
#define print(a) cout<<a<<endl
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define all(x) x.begin(), x.end()
#define loop(i,n) for(int i=0;i<n;i++)
const int MOD = 1e9 + 7;
const ll longinf = 1000000000000000;
void solve();
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin>> t;
	while(t--){
		solve();
	}

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}

vector<int> l;
ll dp[3000][3000];
ll fun(int i,int j)
{
	if(i>j)
		return 0;
	if(dp[i][j] > -longinf)
	{
		return dp[i][j];
	}
    dp[i][j]=max(l[i]-fun(i+1,j),l[j]-fun(i,j-1));
    return dp[i][j];
}
void solve()
{
	int n;
	cin>>n;
	loop(i,n)
	{
		loop(j,n)
		{
			dp[i][j]=-longinf;
		}
	}
	loop(i,n)
	{
		int x;cin>>x;
		l.pb(x);
		dp[i][i]=x;
	}
	cout<<fun(0,n-1);
}
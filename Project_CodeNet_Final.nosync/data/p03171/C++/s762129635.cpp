#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repr(i,a,b) for (int i = a; i > b; --i)
#define mm(lamb, tttt) memset(lamb, tttt, sizeof lamb)
 
#define null NULL
#define eps 0.000000001
#define mod 1000000007
#define PI 3.14159265358979323846
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ALL(V) V.begin(), V.end()
#define sz(V) (int)V.size()
#define _ <<" "<<
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair <int, int> ii;
typedef pair<int, pair<int,int> > iii;
typedef vector<ii> vii;
ll dp[3009][3009];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
	//freopen ("test.txt","r",stdin);
	//string a,b;
	//cin>>a>>b;
	ll n;cin>>n;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	for(int i=n-1 ; i>=0;i--)
	{
		for(int j = i ; j<n;j++)
		{
			if(i==j)
			{
				dp[i][j] = a[i];
			}
			else
			{
				dp[i][j] = max(a[i] - dp[i+1][j] , a[j] - dp[i][j-1]);

			}
		}
	}

	cout<<dp[0][n-1];

}
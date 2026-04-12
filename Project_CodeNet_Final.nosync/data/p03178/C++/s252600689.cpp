#include<bits/stdc++.h>

#define range 100005
#define mod 1000000007
#define eps 1e-9
#define PI 3.14159265358979323846
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ALL(V) V.begin(), V.end()
#define _ <<" "<<
#define int long long 

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair <int, int> ii;
typedef pair<int, pair<int,int> > iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int D;

string K;

int dp[20000][200];
int output=0;


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("test.txt","r",stdin);
	cin>>K>>D;
	for(int i=0;i<10;i++)
	{
		dp[0][i%D]+=1;
	}
	for(int i=0;i<K.length();i++)
	{
		for(int j=0;j<D;j++)
		{
			if(dp[i][j]>0)
			{
				for(int k=0;k<10;k++)
				{
					int remain = (j + k)%D;
					dp[i+1][remain]+=dp[i][j];
					dp[i+1][remain]%=mod;
				}
			}
		}
	}
	int summu = 0;
	reverse(K.begin(),K.end());
	for(int i=K.length()-1;i>=0;i--)
	{
			for(int k=0;k<(K[i] - '0');k++)
			{
				int remain = ( (- summu - k)%D + D)%D;
				if(i==0)
				{
					if(remain==0)
					{
						output+=1;
						output%=mod;
					}
				}
				else
				{
				  output +=dp[i-1][remain];
				  output%=mod;
				}
			}
		summu+=(K[i]-'0');
		summu%=D;
	}
	if(summu==0)
	{
		output+=1;
		output%=mod;
	}
	output = (output -1 + mod)%mod;
	cout<<output<<endl;
	return 0;
}
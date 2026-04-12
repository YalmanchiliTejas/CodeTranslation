#include<bits/stdc++.h>
using namespace std;
#define int  long long 
#define speedrap ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int be(int a,int b,int mod) {if(b == 0) return 1; if(b%2 == 1) return (a*be(a,b-1,mod))%mod; else return (be(a,b/2,mod)*be(a,b/2,mod))%mod;}
const int mod = 1e9 + 7;
#define PI 3.14159265359
#define pf push_front
#define pb push_back
#define bitcount __builtin_popcountll
#define setbitcnt __builtin_ctz
#define sc(a) scanf("%d", &a);
#define sz(s) (int)s.size()
#define eb emplace_back
#define pf push_front
#define mkp(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define roundup(a,b)  std::cout << std::fixed;std::cout << std::setprecision(b); std::cout << a
const int siz = (1e6 + 10);
const int logi = 21;
const double epsilon = 1e-6;
bool cmp(const int &a,const int &b)
{
  return (abs(a-b)>1);
}



signed main()
{
	#ifndef ONLINE_JUDGE
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 	#else
// // online submission
 	#endif 
	speedrap
	int t;
	t = 1;
	//cin>>t;
	int val = 0;
	while(t--)
	{
		int  n;
		cin>>n;
		int a[n];
		int pre[n];
		memset(pre,0,sizeof(pre));
		for(int i = 0 ; i < n ; i ++)
		{
			cin>>a[i];
			if(i == 0)
			{
				pre[i] = a[i];
			}
			else
			{
				pre[i] = pre[i-1] + a[i];
			}
		}

		int sum = 0;

		for(int i = 0 ; i < n-1 ; i++)
		{

			int val1 = a[i];
			int val2 = pre[n-1] - pre[i];

			val1 %= mod;
			val2 %= mod;

			int val = (val1*val2)%mod;

			sum = (sum + val)%mod;
		}

		cout<<sum;
	}
}


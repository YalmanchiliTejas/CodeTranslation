		#include<bits/stdc++.h>
		using namespace std;
		#define sz(x) (int)(x).size()
		#define int long long int
		#define loop(i,a,b) for(int i=a;i<b;i++)
		#define scan(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i]
		#define vi vector<int>
		#define si set<int>
		#define pii pair <int, int>
		#define sii set<pii>
		#define vii vector<pii>
		#define mii map <int, int>
		#define pb push_back
		#define all(aa) aa.begin(), aa.end()
		#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
		//Constants
		const int mod = 1E9+7; /* 1e9 + 7*/
		const int MAXN = 1000005; /*1e6 +5 */
		 
		int spf[1000009]; // stores the smallest prime factor of a number
		 vector<vi> graph;
		// vi count1;
		 
		 int gcdExtended(int a, int b, int *x, int *y); 
		 
		 int count1(int x,int y,int z);
		 //int n;
		void sieve()
		{
			spf[1] = 1;
			for (int i=2; i<MAXN; i++)
				spf[i] = i;
			for (int i=4; i<MAXN; i+=2)
				spf[i] = 2;
		 
			for (int i=3; i*i<MAXN; i++)
				if (spf[i] == i)
				{
					for (int j=i*i; j<MAXN; j+=i)
						if (spf[j]==j)
							spf[j] = i;
				}
		}
		
		void print(vi v)
		{
			for(auto x:v)
			cout<<x<<" ";
			cout<<endl;
		}
		 
		/* Iterative Function to calculate (x^y)%p 	 in O(log y) */
		int power(int x,  int y, int p)
		{
			int res = 1;     // Initialize result
			x = x % p; // Update x if it is more than or
						// equal to p 
			if (x == 0) return 0; // In case x is divisible by p;     
			while (y > 0)
			{
				// If y is odd, multiply x with result
				if (y & 1)
					res = (res*x) % p;     
				// y must be even now
				y = y>>1; // y = y/2
				x = (x*x) % p;
			}
			return res;
		}
		
		 
		void solve()
		{
			int n;cin>>n;
			int arr[n];
			scan(arr,n);
			int prefix[n]={0}, ans=0,s=0;
			loop(i,0,n)
			{
				s+=arr[i];
				s=s%mod;
				prefix[i]=s;
			}
			loop(i,0,n)
			{
				int req=(s%mod -prefix[i]%mod)%mod;
				if(req<0)
				req+=mod;
				ans=(ans%mod + ((arr[i]%mod) *(req%mod))%mod)%mod;
			}
			cout<<ans%mod;
		}

		 
		int32_t main()
		{
			faster;
			int t=1;
			//cin>>t;
			while(t--) solve();		 
			return 0;
		}

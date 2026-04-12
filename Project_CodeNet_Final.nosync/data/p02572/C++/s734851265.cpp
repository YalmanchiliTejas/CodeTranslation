
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
	
	using namespace std;
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n;
			cin>>n;
			int arr[n];
			for(int i=0;i<n;i++)
				cin>>arr[i];
			ll prefix[n]={0};
			prefix[n-1]=arr[n-1];
			for(int i=n-2;i>=0;i--)
				prefix[i]=(arr[i]+prefix[i+1])%1000000007;
			/*for(int i=0;i<n;i++)
				cout<<prefix[i]<<" ";*/
			ll sum=0;
			for(int i=0;i<n-1;i++){
				int p=((arr[i]%1000000007)*(prefix[i+1]%1000000007))%1000000007;
				sum=(sum+p)%1000000007;
			}
			cout<<sum;
		}
		return 0;
	}

/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200005
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
		ll n;
		cin >> n;
		vector<ll> a(maxn),sum(maxn);
		for (int i=0 ; i<n ; i++) 
		{
			cin >> a[i];
			sum[i] = a[i];
		}
		sum[n] = 0;
		for (int i=n-1 ; i>=0 ; i--)
		sum[i]+=sum[i+1];
		
		ll ans = 0;
		for (int i=0 ; i<n ; i++)
		ans = (ans + (a[i] * (sum[i + 1] % MOD))) % MOD;
		cout << ans << endl;
		return 0;
}  

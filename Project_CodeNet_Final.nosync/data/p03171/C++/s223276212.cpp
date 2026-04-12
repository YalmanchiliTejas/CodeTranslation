#include<bits/stdc++.h>
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define pb           push_back
#define ff           first
#define ss           second
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define Pi           2*acos(0.0)
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
using namespace std;

ll expo(ll a,ll b,ll m = mod){
	a%=mod;
	ll res = 1;
	while(b){
		if(b&1)
			res = (res*a)%m;
		a = (a*a)%m;
		b>>=1;
	}
	return res;
}
ll gcd(ll a,ll b){
	while(b>0){
		ll r = a%b;
		a = b; b = r;
	}
	return a;
}
int main()
{
	 
   boost
   #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t=1;
// 	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll A[n];
		ll sum = 0;
		for(int i=0;i<n;i++){
    		cin>>A[i];
    		sum+=A[i];
		}
		if(n==1){
		    cout<<A[0]<<"\n";
		    return 0;
		}
		ll dp1[n][n] , dp2[n][n];
		mem(dp1,0);
		mem(dp2,0);
		for(int i=0;i<n-1;i++){
		    dp1[i][i] = dp2[i][i] = A[i];
		    dp1[i][i+1] = max(A[i],A[i+1]);
		    dp2[i][i+1] = min(A[i],A[i+1]);
		}
		for(int l=3;l<=n;l++){
		    for(int i=0;i<=n-l;i++){
		        int j = i+l-1;
		        dp1[i][j] = max(A[i]+dp2[i+1][j],A[j]+dp2[i][j-1]);
		        dp2[i][j] = min(dp1[i+1][j],dp1[i][j-1]);
		    }
		}
		
		cout<<2*dp1[0][n-1]-sum<<"\n";
	}
    return 0;
}

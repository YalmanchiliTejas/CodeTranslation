#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod=1000000007;
int power(int x, int y, int p) 
{ 
    int res = 1;      
  
    x = x % p;  
  
    while (y > 0) 
    {         if (y & 1) 
            res = (res*x) % p; 
          y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
 int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
} 
int nCrModPFermat(int n, int r, int p) 
{ 
   if (r==0) 
      return 1; 
    int fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
int distancesum(int arr[], int n) 
{ 
    sort(arr, arr + n); 
    int res = 0, sum = 0; 
    for (int i = 0; i < n; i++) 
    { 
        res += ((arr[i] * i - sum)%mod+mod)%mod; 
        sum += arr[i]; 
        sum%=mod;
    } 
    return res; 
} 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,t;
	cin>>n>>m>>t;
	int x[n*m],y[n*m];
	int k=0;
	for(int i=1;i<=n;i++)
	{
		 for(int j=1;j<=m;j++)
		 {
		 	 x[k]=i;
		 	 y[k]=j;
		 	 k++;
		 }
	}
    int res=distancesum(x,n*m)+distancesum(y,n*m);
    res%=mod;
    res*=nCrModPFermat(n*m-2,t-2,mod);
    res%=mod;
    cout<<res<<endl;
}

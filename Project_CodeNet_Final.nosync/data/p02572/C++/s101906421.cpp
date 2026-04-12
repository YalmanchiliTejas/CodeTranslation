 
#include <bits/stdc++.h>
 
 
#define ll long long int  
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(n) for (int i = 0; i < n; ++i) 
#define REP(i,k,n) for (int i = k; i <= n; ++i) 
#define REPR(i,k,n) for (int i = k; i >= n; --i)
 
 
using namespace std;


int mod = (int)1e9 + 7;

long long mMod(long long a, 
                            long long b) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
}

void util(){
	
	int n;cin>>n;

	long long a[n];

	rep(n)
		cin>>a[i];

	long long ans = 0;


	long long sum = 0;

	for(int i =0;i<n;i++){
		sum  = sum + a[i];
	}


	for(int i=0;i<n-1;i++){
		
		sum -= a[i];

		ans = (ans + mMod(a[i],sum))%mod;

		
	}

	cout<<ans<<endl;

}


int main()
{
	/* code */

	
		util();
	

	return 0;
}
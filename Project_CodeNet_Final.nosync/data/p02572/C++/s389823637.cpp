#include<iostream>
#include<algorithm>
using namespace std;
long long  n , a[200005],ans ,b[200005],mod = 1e9+7,sum;
int main(){
     
    cin >> n; 
    for(int i = 1; i <=n ; i++)
    {   
	   cin >> a[i];
	    
	   b[i] = a[i] ;
    }
    
    for(int i = n ; i >= 1 ; i--)
    {
    	 b[i]+=b[i+1];
    	 b[i] = b[i]%mod;
	}
	
	for(int i = 1; i < n; i++)
	{ 
		sum+=(a[i]*b[i+1])%mod; 
		sum%=mod;
	}
	
	cout << sum%mod ;
	return 0;
}
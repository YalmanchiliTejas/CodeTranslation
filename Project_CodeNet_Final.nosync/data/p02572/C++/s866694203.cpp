#include<bits/stdc++.h>
using namespace std;
long long m=1e9 + 7;
long long mod=1e9+7;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

long long modInverse(long long a) 
{ 
    return power(a, m-2);
}

int main()
{
  	int n;
  	cin>>n;
  	
  	long long sum_sq=0;
  	long long sum=0;
  
  	long long a;
  	for(int i=0;i<n;i++)
    {
      	cin>>a;
      	sum=(sum+a)%mod;
      	sum_sq = (sum_sq + a*a%m)%m;
    }
  	sum=(sum*sum)%mod;
  	sum=(sum-sum_sq + mod)%mod;
  
  	cout<<sum*modInverse(2)%m<<endl;
  
  	return 0;
}
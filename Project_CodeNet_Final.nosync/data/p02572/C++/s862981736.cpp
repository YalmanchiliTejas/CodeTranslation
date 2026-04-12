#include<bits/stdc++.h>
using namespace std;
#define forr(i,a,n)     for(long long int i=a; i<n; i++)
#define loop(i,a,n)     for(long long int i=a; i>=n; i--) 

long long int mod=1e9+7;

long long int mul(long long int x,long long int y)
{
    return (x * 1ll * y) % mod;
}
long long int add(long long int x, long long int y)
{
	while(y<0)
		y+=mod;
	while(x<0)
		x+=mod;
	long long int z=x%mod+y%mod;
	while(z>=mod)
		z-=mod;
	while(z<0)
		z+=mod;
	return z;
}
long long int fastpow(long long int x, long long int y)
{
	long long int z=1;
	while(y)
	{
		if(y&1)
			z=mul(x,z);
		x=mul(x,x);
		y/=2;
	}
	return z;
}
long long int inverse(long long int x)
{
	return fastpow(x, mod-2);
}
long long int findProductSum(long long int A[],long long int n) 
{ 
    // calculating array sum (a1 + a2  ... + an) 
   long long int array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = add(array_sum, A[i]);
  	array_sum%=mod;
    // calcualting square of array sum 
    // (a1 + a2 + ... + an)^2 
   long long int array_sum_square = mul(array_sum, array_sum);
  
    // calcualting a1^2 + a2^2 + ... + an^2 
   long long int individual_square_sum = 0; 
    for (int i = 0; i < n; i++) 
        individual_square_sum =  add(individual_square_sum, mul(A[i], A[i])); 
  
    // required sum is (array_sum_square - 
    // individual_square_sum) / 2 
  long long int ans=mul(inverse(2), add(array_sum_square, -individual_square_sum));
  while(ans<0)
  	ans+=mod;
  	return ans;
} 

int main()
{
	ios_base :: sync_with_stdio(false),cin.tie(NULL);
	
	long long int a;
	cin>>a;
	long long int b[a];
	forr(i, 0, a)
		cin>>b[i];
	cout<<findProductSum(b, a);
	
	return 0;
}
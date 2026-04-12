#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x,long long int y) 
{ 
    long long int res = 1;     // Initialize result 
  // x=x;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x); 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x);  // Change x to x^2 
    } 
    return res; 
}
long long int power(long long int x,long long int y,long long int m) 
{ 
    long long int res = 1;     // Initialize result 
   x=x%m;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x)%m; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x)%m;  // Change x to x^2 
    } 
    return res; 
}

long long int gcd(long long int a, long long int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
 long long int lcm(long long int a, long long int b)  
 { 
     long long int temp;
    
    return (a*b)/gcd(a, b);  
 }
 
int main() {
        long long int t=0,b[1000000]={0};
        string c;
        string s;
       long long int n,m,o=0,l,d=0,i,j,p=0,k,f;
       double pie=3.141592653589793238;
    long long int MOD=1000000007;
    cin>>n>>k;
    
        if(k==n)
       // p++;
       cout<<"Yes"<<"\n";
       else
       cout<<"No"<<"\n";
    
    //cout<<P;
 return 0;
}
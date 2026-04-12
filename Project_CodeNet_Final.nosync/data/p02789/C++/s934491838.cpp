#include<bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) 
{ 
    if(b==0) 
        return a; 
    return GCD(b, a % b);  
      
}

long long LCM(long long a, long long b)
{
    long long gcd=GCD(a,b);
     return (a*b)/gcd;
}

int main()
{
    long long i, j, k, n, m, t, x, y, s=0, c=0, l;
    cin >> n >> m;
    if(n==m)
        cout << "Yes\n";
    else
    {
        cout << "No\n";
    }
    
}

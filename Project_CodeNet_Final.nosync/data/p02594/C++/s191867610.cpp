#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define bakku ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod2 1000000007
#define mod 998244353
#define PI 3.1415926535897932384
#define INF LLONG_MAX
#define ff first
#define ss second

//first index greater than key
lli binarysearch(lli arr[], lli l, lli r, lli key)
{
    lli ans = -1; // return -1 if no element is greater than key

    if(arr[r] <= key)
        return (r+1);

    if(arr[l] > key)
        return l;

    while(l <= r)
    {
        lli m = l + (r-l+1)/2;

        if(arr[m] <= key)
            l = m + 1;

        else if(arr[m] > key)
        {
            ans = m;
            r = m - 1;
        }
    }

    return ans;
}

lli max(lli a, lli b)
{
    if(a > b) return a;
    return b;
}

lli min(lli a, lli b)
{
    if(a < b) return a;
    return b;
}



// palindrome
lli pal(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());

    if(temp == str)
        return 1;

    return -1;
}

lli maxSubArraySum(lli a[], lli l, lli r) 
{ 
   lli max_so_far = a[l]; 
   lli curr_max = a[l]; 
  
   for(lli i=l+1; i<r-l+1; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
}

// lli modexp(lli x, lli y, lli mod)  
// {  
//     lli res = 1;     // Initialize result  
  
//     x = x % mod; // Update x if it is more than or  
//                 // equal to p  
  
//     while (y > 0)  
//     {  
//         // If y is odd, multiply x with result  
//         if (y & 1)  
//             res = (res*x) % mod;  
  
//         // y must be even now  
//         y = y>>1; // y = y/2  
//         x = (x*x) % mod;  
//     }  
//     return res;  
// }

lli gcd(lli a, lli b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

lli lcm(lli a, lli b)
{
    lli x = gcd(a, b);
    lli ans = (a*b)/x;
    return ans;
}

lli ncr(lli n, lli r) 
{ 
  
    // p holds the value of n*(n-1)*(n-2)..., 
    // k holds the value of r*(r-1)... 
    lli p = 1, k = 1; 
  
    // C(n, r) == C(n, n-r), 
    // choosing the smaller value 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
  
            // gcd of p, k 
            lli m = __gcd(p, k); 
  
            // dividing by gcd, to simplify product 
            // division by their gcd saves from the overflow 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
  
        // k should be simplified to 1 
        // as C(n, r) is a natural number 
        // (denominator should be 1 ) . 
    } 
  
    else
        p = 1; 
  
    // if our approach is correct p = ans and k =1 
    // cout << p << endl; 

    return p;
}

lli modpow(lli x, lli y, lli p = mod)
{
    lli res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
lli modadd(lli a, lli b, lli m = mod)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}
 
lli modmul(lli a, lli b, lli m = mod)
{
    return ((a % m) * (b % m)) % m;
}
 
lli modi(lli a, lli m = mod) 
{ 
    return modpow(a, m - 2, m); 
}

/*########################################################################*/
/*########################################################################*/
/*########################################################################*/
/*########################################################################*/


int main()
{
    bakku;
    lli testcases = 1;
    // cin >> testcases;

    while(testcases--)
    {
        lli X;
        cin >> X;

        if(X >= 30)
            cout << "Yes\n";

        else
            cout << "No\n";
    }

    return 0;
}

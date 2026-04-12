#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define pb              push_back
#define se              second
#define mp              make_pair
#define fi              first
#define del(a,vec)      vec.erase(std::remove(vec.begin(), vec.end(), a), vec.end());
#define search(f,l,v)   binary_search(f,l,v)
#define iter(a,b)       vector<int>::iterator a,b
#define lower(v,num)    lower_bound (v.begin(), v.end(), num);
#define upper(v,num)    upper_bound (v.begin(), v.end(), num); 
#define removecopy(a)   unique(a.begin(), a.end()); 
#define vi              vector<int> 
#define pi              pair<int,int>    
#define vpi             vector<pi>      
#define mlbb            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)    
int mod =1000000007;
namespace Rahul{
    bool isPrime(int n) 
    {if (n <= 1)  return false; if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
    return true; }
    int pow (int x, int n,int mod) {//calculate x^n
    if (n == 0) return 1;

    int res = pow (x, n / 2,mod);

    res = (res * res) % mod;
    if (n % 2) res = (res * x ) % mod;

    return res;
    }
    int _gcd(int a,int b)
    {
        if(a==0)
            return b;
        else    
            return _gcd(b%a,a);
    }
    //s.erase(s.find(2)) where s={1,2,3,3,2}; 
};
using namespace Rahul;
int32_t main()
{
        
    mlbb;
    
    int a,b;
    cin>>a>>b;
    if(a==b)cout<<"Yes\n";
    else cout<<"No\n";
    
    
}

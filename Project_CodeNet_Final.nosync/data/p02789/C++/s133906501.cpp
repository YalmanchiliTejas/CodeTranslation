#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int         long long   
#define double      long double
#define endl        "\n"
#define pb          push_back
#define PI          3.1415926535897932384626433832795l
#define F           first
#define S           second
#define mp          make_pair
#define f(i,n)      for(int i=0;i<n;i++)
#define fastio      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)      (v).begin(),(v).end()
#define sort(v)     sort((v).begin(),(v).end())
#define rall(v)     (v).rbegin(),(v).rend()
#define rsort(v)     sort((v).rbegin(),(v).rend())
#define gcd(a,b)    __gcd((a),(b))
#define minn(v)     *min_element(v.begin(), v.end());
#define maxx(v)     *max_element(v.begin(), v.end());
#define print(x)    cout<<(x)<<endl;
typedef pair<int,int> pii;  
typedef vector<int> vi;
//x.substr(start, length);

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}
struct type{
    int k, i, j;
};
signed main() 
{
    cout<<fixed<<setprecision(12);
    fastio;
    int n,m;
    cin>>n>>m;
    if(n==m)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    
    
    
}

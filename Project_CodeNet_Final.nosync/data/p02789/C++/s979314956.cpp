#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define pll pair<long long,long long>
#define vl vector<long long>
#define vll vector<pll>
#define vi vector<int>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define tcase int tt; cin>>tt; while(tt--)
#define tcase2 int tt; cin>>tt; for(int qq=1;qq<=tt;qq++)
using namespace std;
typedef long long int ll;
typedef  unsigned long long int ull;
typedef long double ld;
const int MAX = 1000002;
const int MOD2 = 998244353;
const int MOD = 1000000007; 
const int INF = 1e8;
const ld EPS = 1e-7;
// Extra
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define trav(a, x) for(auto& a : x)
#define fill(x,y) memset(x,y,sizeof(x))
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
ll dectobin(ll n,ll p[])
{
    ll i=0 ;
    while(n!=0)
    {
        p[i]=n%2 ;
        n/=2 ;
        i++ ;
    }
    return(i-1) ;
}
ll binarySearchCount(ll arr[], ll n, ll key) 
{ 
    ll left = 0; 
    ll right = n - 1; 
  
    ll count = 0; 
  
    while (left <= right) { 
        int mid = (right + left) / 2; 
  
        // Check if middle element is 
        // less than or equal to key 
        if (arr[mid] < key) { 
  
            // At least (mid + 1) elements are there 
            // whose values are less than 
            // or equal to key 
            count = mid + 1; 
            left = mid + 1; 
        } 
  
        // If key is smaller, ignore right half 
        else
            right = mid - 1; 
    } 
  
    return count; 
} 
void printDivisors(ll n,ll k) 
{  ll temp=1  ;
    // Note that this loop runs till square root 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                {
                	if(i<=k && i>temp)
                	temp=i ;
				}
  
            else // Otherwise print both 
                
                {
                if(i<=k && i>temp)
                	temp=i ;
                if(n/i<=k && n/i>temp)
                temp=n/i ;
				}
        } 
    }
	cout<<n/temp<<"\n" ;
	return ; 
} 
ll solve(ll n)
{
	ll temp=-1 ;
	forn(i,n)
	{
		forn(j,3)
		{
			if(j!=temp)
			{
				
			}
		}
	}
}
int main(int argc, char** argv)
{   sws ;
 //tcase
{
ll n,m ;
cin>>n>>m ;
if(n==m)
cout<<"Yes\n" ;
else
cout<<"No\n";

}
  return 0;
}
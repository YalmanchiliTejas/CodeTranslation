#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <cstring> 
#include <set>
#include <string>
#include <valarray>
#include <vector>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define maxe(v) *max_element(v.begin(), v.end())
#define mine(v) *min_element(v.begin(), v.end())
#define pb push_back
#define pf push_front
#define rem 1000000007
#define cont continue

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll modulo(ll a, ll b)
{
    ll r = a % b;
    return r < 0 ? r + b : r;
}
ll longrem(string k,ll n)
{
    // k is taken into input as a string...
	int now=0;
    for(int i=0;i<k.size();i++)
    {
        now=(now*10)%n;
        now=(now+k[i]-'0')%n;
    }
    return now;    // O( log(k) )/log(10) )
}
ll ncr(ll n,ll k)  
{  
    ll res = 1;  
    if ( k > n - k )  
        k = n - k; 
    for (ll i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
    return res;  
}

ll binaryToDecimal(ll n) 
{ 
    ll num = n; 
    ll dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    ll base = 1; 
  
    ll temp = num; 
    while (temp) { 
        ll last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
  
    return dec_value; 
} 

void decToBinary(int n) 
{ 
    
    int binaryNum[32]; 
  
    int i = 0; 
    while (n > 0) { 
  
         
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 
ll prime(ll n)
{
	ll flag=0;
	if(n==1 || n==2)
	{
		flag=0;
	}
	else 
	{
		if(n%2==0)
			flag=1;
		else
		{
			ll i=3;
			while(i<=sqrt(n) && flag==0)
			{
				if(n%i==0)
					flag=1;
				i=i+3;
			}
		}
	}
	return flag;
}
ll ispal(string str,string s)
{
	ll flag=0;
	reverse(str.begin(), str.end());
	if(str==s)
	{
		flag=1;
	}
	return flag;
}
ll ispalself(string str)
{
	ll flag=0;
	string s=str;
	reverse(str.begin(), str.end());
	if(str==s)
	{
		flag=1;
	}
	return flag;
}
/**************************************************************************************************************************************/
int main()
{
	
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	
	
	/*ll t;
	cin>>t;
	while(t--)
	{*/
	string str;
	ll i,n,cnt=0;
	cin>>str;
	n=3;
	
	
	for(i=0;i<n;i++)
	{
		if(str[i]=='A')
		{
			cnt++;
		}
	}
	
	if(cnt>0 && cnt<3)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}

	
	
	
			
	//}
}
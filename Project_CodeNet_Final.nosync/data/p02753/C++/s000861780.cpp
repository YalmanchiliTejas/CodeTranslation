/* Author:bhagatsunny96
         JGEC
	   template__
	lets_code_it_ */
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long int 
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define test long long int t; cin>>t; while(t-->0)
#define fIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(long long int i=0;i<n;i++)
#define loopr(n) for(long long int i=n-1;i>=0;i--)
#define lrp(a,b) for(long long int i=a;i<=b;i++)
#define lrn(a,b) for(long long int i=b;i>=a;i--)
#define endl '\n'
#define vec vector<ll>v;
#define imap map<ll,ll>mip;
#define umap unordered_map<ll,ll>ump;
#define sett set<ll>st;
using namespace std;
ll gcd(ll a, ll b)
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)  
 {  
    return (a*b)/__gcd(a, b);  
 }
 ll power(ll x, unsigned ll y) 
 { 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
 }
 bool isPrime(ll num)
 {
    bool flag=true;
    for(ll i =2;i<=num/2;i++) 
    {
       if(num%i==0) 
       {
          flag=false;
          break;
       }
    }
    return flag;
}
bool isPalin(ll num)
{
    bool flag=false;
    ll digit,rev=0,n=num;
    do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);
     if(rev==n)
     flag=true;
     return flag;
}
ll sumofdigits(ll n)
{
    ll c=0;
    while(n>0)
    {
        c++;
        n/=10;
    }
    return c;
}
bool sortinrev(const pair<int,int>&a,const pair<int,int>&b) 
{ 
    return (a.first > b.first); 
}
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
string sortString(string &str) 
{ 
   sort(str.begin(), str.end()); 
   return str;
} 
void countSort(ll arr[], ll n, ll exp) 
{ 
	ll output[n];
	ll i, count[10] = {0}; 
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 
void radixsort(ll arr[], ll n) 
{
    ll mx = arr[0]; 
	for (ll i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i];
	ll m =mx;
	for (ll exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 
void print(ll arr[], ll n) 
{ 
    for (ll i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
int main() 
{
    fIO
    string s;
    cin>>s;
    ll n=s.length();
    ll a=0,b=0;
    loop(n)
    {
        if(s[i]=='A')
        a++;
        else
        b++;
    }
    if(a==0 || b==0)
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;
	return 0;
}

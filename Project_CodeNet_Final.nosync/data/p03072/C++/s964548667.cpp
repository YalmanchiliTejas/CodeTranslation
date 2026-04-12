#include <bits/stdc++.h>
#include <functional>
/*
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
*/
using namespace std;
#define int         long long
#define double      long double
#define pb          push_back
#define pf          push_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vpii        vector<pii>
#define mi          map<int,int>
#define vii         vector<vector<int>>
#define mpii        map<pii,int>
#define piii        pair<int,pair<int,int> >
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define PI          3.141592653589
#define bs(v,n)     binary_search(all((v)),(n))
#define lb(v,n)     lower_bound(all((v)),(n))
#define ub(v,n)     upper_bound(all((v)),(n))
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define rf(s)       for(auto &c : s)
#define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++) //use Iterator
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD         1000000007
#define ef else if

/*template<class T>
T big(T a, T b) { return a>b ? a : b; }
int gcd(int a, int b) {  if (a == 0)  return b; return gcd(b % a, a); } 
int lcm(int a, int b) { return (a*b)/gcd(a,b); } 
bool mod(double a,double b) {return a/b - floor(a/b);}
int occurs(vi v,int n)  {  auto it=lb(v,n);auto it1=ub(v,n);int x=it1-it;return x;}
int logb(int base, int x) {return (log(x) / log(base));}
int pow(int n, int m){
    int ans=1;
    fo(i,0,m){
        ans*=n;
    }return ans;
}
int factors(int ans){
    int count=0;
    for (int i=1; i<=sqrt(ans); i++) { 
        if (ans%i == 0) 
        {if (ans/i == i) count++;
            else count+=2;} 
    }
    return count;     
}
bool isSubSequence(string str1, string str2, int m, int n)  // str1<str2
{ 
  
    if (m == 0) return true; 
    if (n == 0) return false; 
  
  	if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    return isSubSequence(str1, str2, m, n-1); 
} */

signed main()
{
tezz;
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
	cin>>a[i];	
}
int max=0,c=0;
for(int i=0;i<n;i++)
{
	if(max<=a[i])
	{
		max=a[i];
		c++;
	}
}
cout<<c<<endl;

return 0;
}
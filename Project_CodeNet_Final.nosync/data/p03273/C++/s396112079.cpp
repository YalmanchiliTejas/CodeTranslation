#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
# include <bits/stdc++.h>
using namespace std;
long long powerexp(long long base, long long exp, int mod) {
   long long res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}
int gcd(int a, int b)
{
    int c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
void PrintVector(vector<long long int> v,long long int n)
{
 
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void Takevector(vector<long long int> &v,long long int n)
{
  for(long long int i=0;i <n;i++)
  { long long int number;
    cin>>number;
    v.push_back(number);
  }
}
typedef long long int ll;
typedef vector<long long int> vi;
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define scl(x)         ll x;       scanf("%lld", &x);
#define scll(x, y)     ll x, y;    scanf("%lld %lld", &x, &y);
#define sclll(x, y, z) ll x, y, z; scanf("%lld %lld %lld", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
#define nl cout<<"\n";
int min(int x, int y)  
{  
    return (x < y)? x: y;  
      
}  

int main()
{
  ll sum=0,tot=0,ans=0;
	int flag=1,flag1=0;
	scii(n,m);
	string s[n];
	rep(i,0,n-1)
	{
		cin>>s[i];
	}  
	rep(i,0,n-1)
	{
		int cnt=0;
		rep(j,0,m-1)
		{
			if(s[i][j]!='.')
				break;
			else cnt++;
		}
		if(cnt==m){
			for(int k=i;k<n-1;k++)
			{
				s[k]=s[k+1];
			}
			n--;
			i--;
		}
			

	}
	// rep(i,0,n-1)
	// {
	// 	cout<<s[i]<<endl;
	// }
	rep(i,0,m-1)
	{
		int cnt=0;
		rep(j,0,n-1)
		{
			if(s[j][i]!='.') break;
			else cnt++;
		}
		if(cnt==n){
			rep(j,0,n-1){
			for(int k=i;k<m-1;k++)
			{
				s[j][k]=s[j][k+1];
			}
		}
		m--;
		i--;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<s[i][j];
		}
		cout<<endl;
	}
return 0;
}
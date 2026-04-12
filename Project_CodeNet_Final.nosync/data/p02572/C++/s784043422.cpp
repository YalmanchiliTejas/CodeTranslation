//******\\
||udc321||	 
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<fstream>
#define ll long long
#define fr(e,r,v) for(int e=r;e<v;e++)
#define bc(e,r,v) for(int e=r;e>v;e--)
#define all(n) (n.begin(),n.end())
#define ft first
#define sd second
#define pb push_back
#define lb lower_bound
#define mpr make_pair
#define db  double
using namespace std;
ll mod=1000000007;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	 ll n;
	 cin>>n;
	 ll a[n];
	 ll s[n];
	 fr(j,0,n)
	 {cin>>a[j];
	 	if(j==0){s[j]=a[j];continue;}
	 	else{s[j]=s[j-1]+a[j];}

	 }
	 ll an=0;
	 fr(j,1,n)
	 {
	 	an+=(a[j]*(s[j-1]%mod))%mod;
	 }
	 cout<<(an)%mod<<endl;
	}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i,k,n) for (ll i = k; i < n; ++i)
#define inputar(a,n) ll a[n];rep(i,0,n)cin>>a[i]
#define PI 3.14159265
const int MOD=1e9+7;


#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a)  (a).begin(),(a).end()

#define test4(x,y,z,a) cerr<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cerr<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cerr<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cerr<<"x is "<<x<<endl;

ll gcd(ll a, ll b) 
{ 
	if (b == 0) 
		return a; 
	return gcd(b, a % b);  
	  
} 

int main()
{
    IOS;
    ll n;
    cin>>n;
    ll a[n+1];
    ll mx=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=mx) ans++;
        mx=max(a[i],mx);
    }
    cout<<ans<<endl;

}
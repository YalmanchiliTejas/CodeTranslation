#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define V vector<int>
#define VLL vector<long long>
#define VV vector<vector<int>>
#define be(x) begin(x),end(x)
#define For(a) for(int i=0;i<a;i++)
#define Forin(a,b) for(int j=a;j<b;j++)
#define len(a) a.size()
#define pb push_back 
#define mp make_pair
#define Um unordered_map
#define S unordered_set
#define mod 1000000007
using namespace std;
ll findProductSum(ll A[], ll n)
{
	ll sum = 0,result=0;
	for (ll i = 0; i < n; i++)
	sum = sum + A[i];
	for(int i=0;i<n;i++)
	{
	    sum-=A[i];
	    result+=((A[i]%mod)*(sum%mod))%mod;
	}
	return result%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
	ll n;
	cin>>n;
	ll a[n];
	For(n) cin>>a[i];
    cout<<findProductSum(a,n)<<"\n";

}

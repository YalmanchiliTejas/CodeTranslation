/* Dsingh_24 */
 
#include<bits/stdc++.h>
#define ll          int
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios	    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
#define N  100005
int lis(int arr[], int n)
{
	// create an empty ordered set S. ith element in S is defined as the
	// smallest integer that ends an increasing sequence of length i
	multiset<int> S;

	// process every element one by one
	for (int i = 0; i < n; i++)
	{
		// insert current element into the set
		auto ret = S.insert(arr[i]);

		// get iterator to inserted element's
		multiset<int>::iterator it;
		it=S.upper_bound(arr[i]);

		// if element is not inserted at the end, then delete next
		// greater element from set
		if (it != S.end())
			S.erase(it);
	}

	// length of LIS is number of elements in the set	
	return S.size();
}
int main()
{
	ios
	ll n,i,j;
	cin>>n;
	ll a[n+1];
	for(i=0;i<n;i++)
		cin>>a[i];
	reverse(a,a+n);
	ll ans=lis(a,n);
	cout<<ans;
	return 0;
}
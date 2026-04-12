#include<bits/stdc++.h>
using namespace std;
#define fl(n)             for(long long int i=0;i<n;i++)
#define sz(a)             int((a).size())
#define tr(c,i)           for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i)          for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define vi                vector <int>
#define vvi               vector < vi >
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define ll                long long
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int> 
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define M                 1000000007LL


int solve()
{
	int n;
	cin>>n;
	ll a[n];
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	ll offset=0,ans=0;
	for(int i=0;i<n;i++)
	{
		offset+=a[i];
		ans+=((a[i]%M)*((sum-offset+M)%M))%M;
		ans=ans%M;
	}
	cout<<ans<<"\n";


  return 0;
}


int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
  
  int t=1;
  //cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}

 
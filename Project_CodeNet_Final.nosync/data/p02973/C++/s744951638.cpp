#include <bits/stdc++.h>

using namespace std;
 
#define int long long
#define ll long long
#define vi vector <int>
#define vii vector <pair<int,int> >
#define rep(i,a,b) for (int i=a;i<b;i++)
#define repD(i,a,b) for (int i=a;i>b;i--)
#define pb push_back
#define pii pair <int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define MOD 1000000007
#define PI 3.14159265359
 
#define deb(x) {x}
#ifndef local
	#define deb(x) ;
#endif
///----------------------------------------------------------------------------------
 
int n;
int arr[100005];


void solve()
{
	cin>>n;rep(i,0,n)cin>>arr[i];
	
	int ans=0;
	vi source;
	
	source.pb(arr[n-1]);
	
	repD(i,n-2,-1)
	{
		int pos=upper_bound(all(source),arr[i])-source.begin();
		if (pos==source.size())source.pb(arr[i]);
		else source[pos]=arr[i];
	}
	cout<<source.size();
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    #ifdef local
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    clock_t qwertyuiop = clock();
    #endif
 
 
    int t=1;
   // cin>>t;
    
    rep(a,0,t)
    {
        ///cout<<"Case #"<<a+1<<": ";
        solve();
    }
    #ifdef local
	{qwertyuiop = clock() - qwertyuiop;double time_taken = ((double)qwertyuiop)/CLOCKS_PER_SEC;cerr<<fixed<<setprecision(5)<<"\n\nTime Taken : "<<time_taken<<" seconds\n";}
	#endif
}
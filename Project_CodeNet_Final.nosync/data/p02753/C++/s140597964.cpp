#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds; 
#define mod 1000000007
#define int long long
#define pb push_back
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inp(n) for(i=0;i<n;i++) cin>>A[i];
#define inz(A) memset(A,0,sizeof(A))
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define T 1000000
#define F first
#define S second
#define pi pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define vp vector<pair< int,int> >
#define mpi map<pair<int,int> ,int>
#define mip map<int, pair<int,int> >
#define inf INT_MAX
#define inf1 LONGLONG_MAX
#define sz(v) v.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define deb(x) cout<<#x<<"is "<<x<<endl;
#define lower(s) transform(all(s),s.begin(),::tolower)
#define endl "\n"
typedef tree<int, null_type, less<int>, rb_tree_tag, 
         tree_order_statistics_node_update> pbds;
   
/* brownsands :Arpit */			

void solve()
{   string s;
    cin >> s;
    if((s[0]=='A' || s[1]=='A' || s[2]=='A') && ((s[0]=='B' || s[1]=='B' || s[2]=='B')))
    cout<<"Yes";
    else cout<<"No";
}
signed main()
{
   boost
        int test=0,t;
		//cin>>t;
		t=1;
		while(test++ <t){
            //cout<<"Case "<<test<<": ";
            solve();
            //cerr << "\nTime : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
               }		
} 
               
			
 

				
		
		



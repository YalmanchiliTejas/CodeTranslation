/*Author : Kartik Bansal
 *Date : 07/09/19
*Time : 16:14 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define tc int t ;cin>>t ;while(t--)
#define pb push_back
#define mp make_pair
#define FOR(i,n) for(int i =0;i<n;i++)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define tra(a) for(auto it : a )cout<<it<<" " ;
#define all(v) v.begin() , v.end()
#define vi  vector<int>
#define vll  vector<long long >
#define vpp vector<pair<int , int >>
#define inf INT_MAX
#define minf INT_MIN
#define ss second
#define ff first
int main()
{
       ios::sync_with_stdio(0) ;
       cin.tie(0) ; cout.tie(0) ;
		 // #ifndef ONLINE_JUDGE
  	// 		    freopen("input.txt", "r", stdin);
 		// 	    freopen("output.txt", "w", stdout);
   //    #endif
 			    string s ; 
 			    cin>>s ;
 			    set<char> ss ; 
 			    FOR(i , 3 )
 			    {
 			    	ss.insert(s[i]); 
 			    }
 			    if(ss.size() >= 2 )
 			    	cout <<"Yes\n" ; 
 			    else 
 			    	cout<<"No\n" ; 

 			    

  return 0 ;
}

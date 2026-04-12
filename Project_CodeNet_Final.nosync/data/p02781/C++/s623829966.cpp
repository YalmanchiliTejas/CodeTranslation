#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>


/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/
using namespace std;
using namespace __gnu_pbds;

// #define  part ..
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end() 
#define mod 1000000007
//#define maxx 200006
#define ll long long 
#define quick    ios_base::sync_with_stdio(NULL),cin.tie(0);
#define listll vector< long long > 
#define listi vector< int> 
#define pii   pair<int , int> 
#define pll pair<long long , long long > 
#define minheap priority_queue<long long , vector< long long >, greater<long long > >
#define rep(i,a,b) for(int i=a;i<b;i++)
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


template < class T > using oset = tree< T , null_type, less  < T  > , rb_tree_tag , tree_order_statistics_node_update > ;


// end of #define 

// define globals ...
const int maxx = 2e5+26;

//write function from here ...


int n,k;
ll dp[111][4][2];
ll st[111];



ll dpp ( int len , int ck ,bool f){
	
	if(len == n+1)
	return ck==k;
	
	if(ck > k )
	return 0;
	
	
	if(dp[len][ck][f]!=-1)
	return dp[len][ck][f];
	
	
	ll ret =0 ;
	ll p = f? st[len-1] : 9;
	
	for( ll i =0; i <= p;i++){
		
		
		ret+= dpp(len+1, ck+ (i!=0), f && (i==p) ) ;
		
		
	} 
	
	 	
	
	
	
	return dp[len][ck][f] = ret;
}





int Main(){



string s;
cin>>s;

cin>>k;
n = s.length();


for(int i =0 ; i < k+1; i++)

memset(dp,-1,sizeof(dp));


int i=0 ;
for(auto c:s ) {
	
	st[i++]= c - '0';
}

   cout << dpp(1,0,1);


return 0;

}



int main(){
 quick;
int t =1; 
//cin>>t;
while(t-- )
 Main();

 return 0;


}

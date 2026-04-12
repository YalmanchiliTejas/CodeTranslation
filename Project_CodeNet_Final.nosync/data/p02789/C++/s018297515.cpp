/**akshaykumar99**/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template<typename T> using id_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> ;
template<typename T> using id_setp = tree<pair<T,T>,null_type,less<pair<T,T>>,rb_tree_tag,tree_order_statistics_node_update> ;
 
#define f(i,x,n) for(i=x;i<n;i++)
#define fr(i,x,n) for(i=x;i>=n;i--)
#define pu push_back           
#define pp pop_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SP(x) fixed<<setprecision(x)
#define IOS() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const long long MOD=1e9+7;
const long double PI = acos(-1);
const long long INF=INT_MAX;
const long long LINF=LLONG_MAX;
const long long N=2e5+1;
 
typedef long long ll;
typedef long double ld;

int main()
{
    IOS();
    
   	ll n,m,i,j;
   	cin>>n>>m;
   	if(n==m)
   		cout<<"Yes\n";
   	else
   		cout<<"No\n";
    return 0;
}
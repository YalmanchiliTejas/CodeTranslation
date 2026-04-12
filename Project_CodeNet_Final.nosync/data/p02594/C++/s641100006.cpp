#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/detail/standard_policies.hpp>

// common
#define endl     "\n"
#define M_PI     3.14159265358979323846

// fast input output
#define fast_io  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL)

// fixed float field
#define fix_prec cout.setf( std::ios::fixed, std:: ios::floatfield ); cout.precision(9);

// vector
#define vi       vector<int>
#define vvi      vector<vector<int>>
#define vpii     vector<pair<int,int>>
#define pb(v,x)  v.push_back(x)

// pair
#define pii      pair<int,int>
#define mp(a,b)  make_pair(a,b)
#define F        first
#define S        second

// sort
#define all(x)   x.begin(),x.end()

// bound
#define lb(v,x)  lower_bound(v.begin(),v.end(),x)
#define ub(v,x)  upper_bound(v.begin(),v.end(),x)

using namespace std;
//using namespace __gnu_pbds;

//typedef tree < int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
typedef long long int lli;
typedef unsigned long long int ulli;

// constants
lli const mod  = 1e9;
lli const modl = 1e18;

void solve()
{
	int x;
	cin>>x;
	if(x>=30)
		cout<<"Yes";
	else
		cout<<"No";
}

int main()
{
  fast_io;
  fix_prec;
  int t=1;
  //cin>>t;
  while(t--)
  {
    solve();
    cout<<endl;     
  }
  return 0;	
}

#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
#include<bits/stdc++.h>
#define int long long
#define pb push_back 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define repa(i,a,b) for (int i=a; i<=b; i++)
#define repd(i,b,a) for (int i=b; i>=a; i--)
#define endl "\n"
typedef tree<int, null_type, less<int>, 
rb_tree_tag, tree_order_statistics_node_update> pbset; 
//debugging
#define debug1(a) cout<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;

const int N = 1e+6+5;
int big = 1e+18+3;
int mod = 1e+9+7;

signed main()
{
    IOS;
    int x; cin>>x;
  	if (x>=30)
      cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
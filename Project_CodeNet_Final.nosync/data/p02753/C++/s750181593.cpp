#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long int
#define pb push_back
#define mp make_pair
#define loop(i,x,n) for(int i=x;i<=n;i++)
#define rloop(i,x,n) for(int i=x;i>=n;i--)
#define ff first
#define ss second
#define N4RUTO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
typedef tree<int, null_type, less<int>, rb_tree_tag,  
tree_order_statistics_node_update>
ordered_set;
 
int32_t main(){
    N4RUTO;
    string s;
    cin>>s;
    if(s[0]==s[1] && s[1]==s[2]) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}
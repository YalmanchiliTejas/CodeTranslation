#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ll long long
#define fast std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
 
 //string ans="";
/*ll solve(ll n )
 {
     if(n<12)
        return n;
     if(mp[n]==0)
            mp[n]=max(solve(n/2)+solve(n/3)+solve(n/4),n);
     return mp[n];
        
 }
*/
int main(){
   fast;
    ll x;
    cin>>x;
    if(x>=30)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
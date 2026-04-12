#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a,ll b){
if(b==0)
    return 1;
if(b==1)
    return a;
ll t=power(a,b/2);
if(b%2==0)
    return t*t;
return a*t*t;
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("ouput.txt","w",stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    */

ll t;
cin>>t;
if(t>=30)
    cout<<"Yes\n";
else
    cout<<"No\n";
    return 0;
}

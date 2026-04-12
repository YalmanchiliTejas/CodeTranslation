#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

void solve()
{
    ll n,ans=0;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    ll t = (pow(10,9)+7);
    ll  pre = arr[0];
    for(ll i=1;i<n;i++)
    {
    	ans = (ans+(arr[i]*pre)%t)%t;
    	pre = (arr[i] + pre)%t;
    }
   // cout<<ans<<endl;
    
    cout<<(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    #ifdef JAY
        freopen("C:/Users/jayra/Desktop/cp/input.txt","r",stdin);
        freopen("C:/Users/jayra/Desktop/cp/output.txt","w",stdout);
    #endif
	 {
        solve();
   }
}
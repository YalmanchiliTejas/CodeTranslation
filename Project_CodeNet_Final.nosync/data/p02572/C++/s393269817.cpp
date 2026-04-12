#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vll vector<long long int> 
#define pb push_back
#define f(i,x,n) for (i=x;i<n;i++)

#define mx 1000000007
ll prod(ll temp,ll x){
    if(temp<x)
    swap(temp,x);
    if(x==0)
    return 0;
    ll y=temp;
    for(ll i=1;i<x;i++){
        temp=(temp+y)%mx;
    }
    return temp;
}
void solve(){
    ll n;
    cin >> n;
    ll a[n];
    ll sum=0;ll ans=0;
    ll pref[n+1];
    pref[0]=0;
    for(ll i=0;i<n;i++){cin >> a[i];
        ans=(ans+(sum*a[i])%mx)%mx;
        sum=(sum+a[i])%mx;
        
    }
    cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(false); 
     	cin.tie(NULL);
	int t=1;
	while(t--)
	solve();	
	
}

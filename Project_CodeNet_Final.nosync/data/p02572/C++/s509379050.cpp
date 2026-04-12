#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define f(i,a,b,c) for(ll i=a;i<b;i+=c)
#define r(i,a,b,c) for(ll i=a;i>=b;i-=c)
#define mod 1000000007
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n; cin >> n;
    ll ar[n];
    ll sum = 0;
    f(i,0,n,1){
    	cin >> ar[i];
    }
    ll in = ar[n-1];
    r(i,n-1,1,1){
    	//cout << in << "\n";
    	sum += (ar[i-1]*in);
    	in += ar[i-1];
    	sum%=mod;
      	in%=mod;
    	//cout << ar[i-1] << " " << sum  << " " << in << "\n"; 
    }
    cout << sum;
    return 0;
}
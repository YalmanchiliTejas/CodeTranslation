#include <bits/stdc++.h>
#include <iomanip>
#define M 100000
#define MAX 1000000001
#define MIN -10000000000000000
#define mod 1000000007
#define ss second
#define ff first
#define ll long long int
#define pb push_back
#define ld double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll pre[n+1] = {0},ans = 0;
    for(int i=n-1;i>=0;i--){
        pre[i] = (pre[i] + pre[i+1]+a[i])%mod;
    }
    for(int i=0;i<n;i++){
        ans = (ans + (a[i]*pre[i+1])%mod)%mod;
    }
    cout<<ans<<"\n";
    return 0;
        
}

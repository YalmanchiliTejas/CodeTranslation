#include <bits/stdc++.h>
#define vc vector<int>
#define um unordered_map<int,int>
#define ll long long 
#define rep(i,a,b) for(__typeof(a) i=a; i<b; i++)
#define si(a) a.size()
#define all(a) a.begin(),a.end()
#define ss(a) a.second
#define ff(a) a.first
#define M 1000000
#define pb push_back
#define repit(i,a) for(auto i=a.begin(); i!=a.end(); i++)
#define take(arr,n) for(int i=0;i<n;i++)cin>>arr[i]
#define out(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<' '
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define reprev(i,b,a) for(__typeof(b) i=b; i>=a; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define doublearray vector<vector<int>>
#define mod 1000000007 
using namespace std;
ll max(ll a, ll b){ return a>b?a:b; }
ll min(ll a, ll b){ return a<b?a:b; }
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
int binaryS(int x, int sb[], int m){
    int l = 0, r=m;
    int mid = (l+r)/2;
    while(l<r){
        mid = (l+r)/2;
        if(sb[mid]<x) l= mid+1;
        else if(sb[mid]>x) r = mid-1;
        else return mid;
    }
    return l;
}
int main(){
    fastio;
    // int t; cin>>t;
    // while(t--){
      ll n; cin>>n;
      ll arr[n]; take(arr,n);
      ll su[n+1]; su[n]=0;
      reprev(i,n-1,0){
          su[i] = (su[i+1]+arr[i])%mod;
      }
      ll ans = 0;
      rep(i,0,n-1){
          ans = (ans+(su[i+1]*arr[i])%mod)%mod;
      }
      cout<<ans<<endl;
    return 0;
}

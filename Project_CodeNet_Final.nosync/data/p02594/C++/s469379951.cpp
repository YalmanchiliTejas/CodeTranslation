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
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define reprev(i,b,a) for(__typeof(b) i=b; i>=a; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define doublearray vector<vector<int>>
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
ll ans(ll a){
    return a<0?a+MOD:a;
}
int main(){
  int n; cin>>n;
   cout<<(n>=30?"Yes":"No")<<endl;
          return 0;
          }




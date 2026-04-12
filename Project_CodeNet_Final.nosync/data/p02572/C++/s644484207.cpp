#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pai(k) pair<k,k>
#define mod 1000000007
#define mpai make_pair
#define p1 first
#define p2 second
#define pb push_back
#define umap(x,y) unordered_map<x,y>
static void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);}

int main()
{
fast();

    ll n=0;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
	cin>>arr[i];
}
ll dp[n]={0};
dp[n-1] =arr[n-1];
for(int i=n-2;i>=0;i--){
	dp[i]=(dp[i+1]+arr[i])%mod;
}
ll sum=0;
for(int i=0;i<n-1;i++){
	sum = (sum+(arr[i]*(dp[i+1])%mod)%mod)%mod;
}
cout<<sum<<"\n";

return 0;
}

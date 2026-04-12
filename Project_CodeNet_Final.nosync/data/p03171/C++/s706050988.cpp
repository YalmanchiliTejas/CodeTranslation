#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> 
#define ff first 
#define endl "\n"
#define ss second 
#define li list<int>
#define vi vector<int>
#define ll long long int
#define pii pair<int,int>
#define vii vector<pair<int,int> >
#define mp make_pair
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define custom  pair<int,pair<int,int> >
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; 
#define mod 1000000007
ll dp[3001][3001];
ll solve(int* arr,int i,int j){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll op1=arr[i]+min(solve(arr,i+1,j-1),solve(arr,i+2,j));
    ll op2=arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1));
    return dp[i][j]=max(op1,op2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    memset(dp,-1,sizeof dp);
    ll bak=solve(arr,0,n-1);
    ll sak=sum-bak;
    cout<<bak-sak;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ff                first
#define ss                second
#define pb                push_back
#define int                long long
#define forn(i, n)        for (int i = 0; i < n; i++)
#define Forn(j, a, b)     for (int j = a; j < b; j++)
#define sp                " "
#define br                "\n"
#define mii               map<int ,int>
#define setbits(x)        _builtin_popcountll(x)
#define zrobits(x)        _builtin_ctzll(x)
#define ps(x,y)           fixed<<setprecision(y)<<x
#define w(x)              int x; cin>>x; while(x--)
#define MAXN              10000000
void c_p_c()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("ou.txt", "w", stdout);
#endif
}
//map--------------------------
// auto it=map.begin();
// for(it;it!=map.end();++it)
// {

// }
// int dp[100002][6];
// int fun(int arr[],int i,int k,int z,int n)
// {
//   if(i>=n||k==0||i<0)
//   return 0;
//   if(dp[i][z]!=-1)return dp[i][z];
//   int value=0;
//   if(i<n)
//   value=max(value,arr[i]+fun(arr,i+1,k-1,z,n));
//   if(i>0 and z>0)
//   value=max(value,arr[i]+fun(arr,i-1,k-1,z-1,n));
//   return dp[i][z]=value;
// }


//char num[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};


void solve()
{
  int x;cin>>x;
  if(x>=30)cout<<"Yes";
  else cout<<"No";
}
int32_t main()
{
  c_p_c();
  solve();
}   

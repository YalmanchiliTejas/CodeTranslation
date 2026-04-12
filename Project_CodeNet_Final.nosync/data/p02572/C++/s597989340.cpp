#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
  int n;
  cin>>n;
  vll arr(n);
  fr(i,0,n){
    cin>>arr[i];
  }
  vll pre(n,0);
  pre[n-1]=arr[n-1];
  fri(i,n-2,0){
    pre[i]=(pre[i+1]+arr[i])%MOD;
  }
  ll sum=0;
  fr(i,0,n-1){
    sum=(sum+ arr[i]*pre[i+1])%MOD;
  }
  cout<<sum<<endl;
  return;
}

int main()
{
  boost();
  
  int tc=1;
  //cin>>tc;
  while(tc--)
    solve();
  return 0;
}
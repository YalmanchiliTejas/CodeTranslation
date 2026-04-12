#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define INF 1020304050

int main()
{
  int n;cin>>n;
  vector<int> a(n);
  int i;
  rep(i,n)cin>>a[i];
  rep(i,n)a[i]*=(-1);
  vector<int> dec(n,INF);
  rep(i,n)
  {
    int ind=upper_bound(all(dec),a[i])-dec.begin();
    dec[ind]=a[i];
  }
  int ans=0;
  rep(i,n)
  {
    if(dec[i]!=INF)ans++;
    else break;
  }
  cout<<ans<<endl;
}

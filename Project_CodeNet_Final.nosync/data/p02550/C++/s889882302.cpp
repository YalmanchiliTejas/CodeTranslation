#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;

void solve()
{
  int mx=50000000;
  int n,x,m;
  cin>>n>>x>>m;
  mx=min(mx,n);
  int prev=x;
  int ans=x;

  ///r.push_back(x);
  unordered_map<int,int> mp;
  mp[x]=1;
  int ok=0;
  int freeze=0;
  vector<int> res;
  res.pb(x);
  for(int i=2;i<=mx;i++)
  {
      prev*=prev;
      prev%=m;
      if(!mp[prev])
      {
          mp[prev]=1;
      res.pb(prev);
      }
      else if(!ok)
      {
          ok=1;
          freeze=prev;
      }
      ans+=prev;
  }

  if(prev==0)
  {//cout<<"yes"<<endl;
      cout<<ans<<endl;
  }
  else if(prev==1)
  {
      ans+=n-mx;
      ///cout<<"yes"<<endl;
      cout<<ans<<endl;
  }
  else
  {

      int i=0;
      n-=mx;
      if(n==0)
      {
          cout<<ans<<endl;
          return;
      }
      vector<int> cyc;
      int yes=0;
      for(int i=0;i<res.size();i++)
      {
          if(res[i]==freeze)
          {
              yes=1;
          }
          if(yes)
            cyc.pb(res[i]);
      }
      ///cout<<n<<" "<<ans<<endl;
      for( i=0;i<cyc.size();i++)
      {
          if(cyc[i]==prev)
          {
              i++;
              break;
          }
      }

      for(;i<cyc.size();i++)
      {  if(n==0)
      break;
          ans+=cyc[i];
          n--;
      }
      if(n==0)
      {
          cout<<ans<<endl;
          return;
      }
      int sum=0;

      int r=cyc.size();
      for(int i=0;i<r;i++)
      {
          sum+=cyc[i];
      }
            if(r==0)
            {
                cout<<ans<<endl;
                return;
            }
      int f=(n/r);
      f*=sum;

      ans+=f;

      n=n%r;

      for(i=0;i<n;i++)
      {
          ans+=cyc[i];
      }
      cout<<ans<<endl;
  }


}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
    return 0;
}

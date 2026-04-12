/*
I believe on myself and I will achieve
this->author = Fuad Ashraful Mehmet, CSE-UAP
Todo:
https://codeforces.com/contest/1398/problem/E
https://codeforces.com/problemset/problem/374/C
*/
#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<(int)n;++i)
#define all(o) (o).begin(),(o).end()
#define dbg(o)  cerr<<"at "<<__LINE__<<" response = "<<o<<endl;
#define pb push_back
using namespace std;

const int N=2e5+5;
int n,k,m;
#define ll long long
ll a[N];
ll pref[N];

const ll mod=1e9+7;

void HalfDead()
{
      cin>>n;
      for(int i=1;i<=n;++i)
      {
            cin>>a[i];
      }

      for(int i=1;i<=n;++i)
      {
            pref[i]=pref[i-1]+a[i];
            pref[i]%=mod;
      }


      ll res=0;

      for(int i=1;i<=n;++i)
      {
            ll sum=pref[i-1];
            res+=(sum*a[i]);
            res%=mod;
      }

      cout<<res<<endl;
}
int main()
{
      ios_base::sync_with_stdio(0); cin.tie(nullptr);  cout.tie(0);
      int tc=1;
     // cin>>tc;
      while(tc--)
      {
            HalfDead();
      }
      return 0;
}
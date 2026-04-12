#include<bits/stdc++.h>
#include<sstream>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define loop(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revloop(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define stloop(it,v) for(it=v.begin();it!=v.end();++it)
#define ii pair<ll,ll>
#define MP make_pair
#define pb push_back
#define f first
#define s second
#define ll long long int
#define vi vector<int>
#define rs resize
int main()
{  std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n,i,j;
   cin>>n;
   string a;
   map<char,int> mp,mpf;
   loop(i,0,n)
   {
    cin>>a;
    loop(j,0,a.length())
     mp[a[j]]++;
    if(i==0)
    {
      for(auto &it:mp)
        mpf[it.f]=it.s;
    }
    else
    { for(auto &it:mpf)
       it.s=min(it.s,mp[it.f]);
    }
    mp.clear();
   }
   bool flag=false;
   for(auto &it:mpf)
   {
     if(it.s!=0)
     {
       flag=true;
       loop(j,0,it.s)
        cout<<it.f;
     }
   }
   if(!flag)
    cout<<endl;
   return 0;
}

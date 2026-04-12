#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define mod 1000000007
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
   ll n,m;
   cin>>n>>m;
   vector<string>s(n);
   ll i,j;
   for(i=0;i<n;i++)
   {
       cin>>s[i];
   }

   unordered_map<ll,ll>mpi,mpj;
   for(i=0;i<n;i++)
   {
       ll flag=1;
       for(j=0;j<m;j++)
       {
           if(s[i][j]=='#')
           {
               flag=0;
               break;
           }
       }
       if(flag)
       {
           mpi[i]++;
       }
   }

   for(i=0;i<m;i++)
   {
       ll flag=1;
       for(j=0;j<n;j++)
       {
           if(s[j][i]=='#')
           {
               flag=0;
               break;
           }
       }
       if(flag)
       {
           mpj[i]++;
       }
   }

   vector<string>ans;
   string ss;

   for(i=0;i<n;i++)
   {
       ss="";
       for(j=0;j<m;j++)
       {
           if(mpi[i]>0 || mpj[j]>0)
           {
               continue;
           }
           else
           {
               ss+=s[i][j];
           }
       }
       ans.pb(ss);

   }

   for(i=0;i<ans.size();i++)
   {
       if(s[i]!="")
       {


            cout<<ans[i]<<endl;
       }
   }
}

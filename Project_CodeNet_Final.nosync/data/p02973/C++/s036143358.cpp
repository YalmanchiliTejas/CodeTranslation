#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair

using namespace std;


int main()
{
   FAST/**/
   
   ll n;
   cin>>n;
   
   pair<ll,ll> arr[n];
   for(ll i=0;i<n;i++)
   {
       cin>>arr[i].first;
       arr[i].second = i;
   }
   
   sort(arr,arr+n);
   
   map<ll,ll> ma;
   //ma[make_pair(arr[0].second, arr[i].first)] = 1;
   
   for(ll i=0;i<n;i++)
   {
       ll j;
       vector<pair<ll,ll>> hold;
       
       auto it1 = ma.lower_bound(arr[i].second);
       if(it1 == ma.begin())
           hold.pb(mp(arr[j].second,1));
       else{
       it1--;
       ll temp = it1->second;
       ma.erase(it1);
       hold.pb(mp(arr[i].second,temp+1));
       }
       
       for(j=i+1;j<n;j++)
       {
           if(arr[j].first != arr[i].first)
               break;
           if(ma.size() == 0)
           {
               hold.pb(mp(arr[j].second,1));
               continue;
           }
           
           auto it = ma.lower_bound(arr[j].second);
           if(it == ma.begin())
           {
               hold.pb(mp(arr[j].second,1));
               continue;
           }
           
           it--;
           ll temp = it->second;
           ma.erase(it);
           hold.pb(mp(arr[j].second,temp+1));
       }
       
       for(ll i1=0;i1<hold.size();i1++)
            ma[hold[i1].first] = hold[i1].second;
       
       i=j-1;
       
   }
   
   cout<<ma.size();
   
   return 0;
}
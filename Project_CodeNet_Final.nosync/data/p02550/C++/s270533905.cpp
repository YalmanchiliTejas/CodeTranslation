//Bismillah Hir Rehmanir Rahim
//Allah knows best
using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define endl "\n"
#define mini -10000000000000000
#define start ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i, a, n) for( i=a; i<n;i++)
#define ll long long
#define pi 3.141592653589793
#define vi              vector<int>
#define si              set<int>
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
#define setbits(x)      __builtin_popcountll(x)
#define zrbits(x)       __builtin_ctzll(x)
#define deb(x)          cout << #x << " = " << x << endl
int main()
{
   start;
   ll i,j,k,n,m;
   cin>>n>>k>>m;
   vector<ll>ami;
   ll ans=0;
   for(i=k,j=0;j<m+5;j++)
   {
       if(j<=n-1)
       {
           ans+=(i%m);
       }
       ami.pb(i%m);
      if(j==n-1)
      {
        cout<<ans<<endl;
        rr;
       }
       i=i%m;
       i=i*i;
        i%=m;
   }
   ll ajob=ami.size();
   ll st;
   for(i=0;i<ajob;i++)
   {
       if(ami[i]==ami[ajob-1])
       {
         st=i;
         break;
       }
   }
   ll len;
   for(i=st+1;i<ajob;i++)
   {
       if(ami[st]==ami[i])
       {
           len=i-st;
           break;
       }
   }
   i-=len;
   ans=0;
   for(j=0;j<i;j++) ans+=ami[j];
   ll l_sum=0;
   for(i=st,j=0;j<len;i++,j++)
   {
       l_sum+=ami[i];
   }
   ll bad=n-st;
   ll ro=bad/len;
   ans=ans+ro*l_sum;
   bad=(n-st)%len;
    for(i=st,j=0;j<bad;i++,j++)
        ans+=ami[i];
   cout<<ans<<endl;
   rr;
}
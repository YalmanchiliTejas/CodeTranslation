#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define int long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N=1e5+5;

int32_t main()
{
    IOS;

    int n,ans=0;
    
    cin>>n;
    
    int a[N];
    
    for(int i=1;i<=n;i++)
     cin>>a[i];
    
    sort(a+1,a+1+n);
    
    deque <int> fun;
    
    fun.push_front(a[1]);
    fun.push_back(a[n]);
    
    int i,j;
    
    for(i=2,j=n-1;i<j;)
    {
         int x=fun.front();
         int y=fun.back();
         
         int var1=max(abs(a[i]-x),abs(a[i]-y));
         int var2=max(abs(a[j]-x),abs(a[j]-y));
         
         if(var1>var2)
         {
          if(abs(a[i]-x)>abs(a[i]-y))
               fun.push_front(a[i]);
          else
               fun.push_back(a[i]);
               i++;
         }
         else
         {
              
               if(abs(a[j]-x)>abs(a[j]-y))
               fun.push_front(a[j]);
               else
               fun.push_back(a[j]);
               j--;
         }
                  
    }
    
    if(i==j)
    {
         int x=fun.front();
         int y=fun.back();
         
         
         if(abs(a[i]-x)>abs(a[i]-y))
          fun.push_front(a[i]);
         else
          fun.push_back(a[i]);
    }
    
    deque <int> :: iterator it,itr; 
    
    for(it=fun.begin();it!=fun.end();it++)
    {
         itr=it+1;
         if(itr==fun.end())
          break;
          
          ans+=abs(*it-*itr);
    }
    
    cout<<ans;
    
    return 0;

}
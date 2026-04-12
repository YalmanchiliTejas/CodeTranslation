#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<chrono>
#include<typeinfo>
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds; 
#define lli long long int
#define fr(i,a,b) for(lli i=a;i<b;i++)
#define bfr(i,a,b) for(lli i=a;i>=b;i--)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL),cout.tie(NULL);
#define tc int t;cin>>t;while(t--)
//#define mod 1000000007LL
#define mod2 998244353LL
#define all(vec) vec.begin(),vec.end()  
#define ld long double
#define pb push_back
#define ordered_set tree<lli, null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update> 
lli mod;
lli power(lli x,lli y)
{
     lli res=1;
     while(y>0)
     {
        if(y&1)res = ((res%mod)*(x%mod))%mod;
        y>>=1;
        x= ((x%mod)*(x%mod))%mod;
     }
     return res;
}

int main()
{
   
         

    fio

    lli n,x,m;
    cin>>n>>x>>m;

    
    mod=m;
    

    map<lli,lli> h;
    lli dp[100010]={0};

    lli start=-1,end=-1;
    h[x]=0;
    dp[0]=x%m;
    fr(i,0,n-1)
    {
       lli o = power(x,2);
       if(h.count(o)==0){h[o]=i+1;dp[i+1]=o;}
       else {start=h[o],end=i+1;break;}
       x=o;
       //cout<<x<<'\n';
    }

    lli ans=0;
    if(start==-1)
        {for(auto z:h)ans+=z.first;cout<<ans<<'\n';}
    else
    {

        //cout<<start<<" "<<end<<'\n';
       n=n-start;
       lli o =0;
       fr(i,0,start)ans+=dp[i];
       fr(i,start,end)o+=dp[i];
       lli z=(n%(end-start));
       ans+=(n/(end-start))*o;
       fr(i,start,z+start)ans+=dp[i];
       cout<<ans;
    }





  
     

    


     

     


    
      




 

return 0;}
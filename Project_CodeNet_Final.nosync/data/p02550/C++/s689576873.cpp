#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <iostream> 
#include<bits/stdc++.h>
using namespace __gnu_pbds;  
using namespace std;  

// Declaring ordered_set 
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set;  
// https://www.geeksforgeeks.org/order_of_key-in-c/
 
typedef pair<long long int,long long int> pa;
 
#define resize(A) A.resize(unique(A.begin(), A.end()) - A.begin())
#define pb push_back
#define  MAX 1000001

#define endl "\n"                   //Take care in case of interactive problems





long long int mod=998244353;
long long int MOD=1e9+7;
long long int INF=1e18;
 

 
//long long int R[4]={1,0,-1,0};
//long long int C[4]={0,1,0,-1};
 


void fastio()
{
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);
      cout.tie(NULL);
}
 
//////////////////////////////////////////////sieve//////////////////////////////////////////////////////////////////

/*
bool C[MAX];
vector<long long  int>V;
void sieve()
{
    long long int i,j;
    for(i=2;i<MAX;i++)
    {
      if(!C[i])
     { 
        V.pb(i);
        
        for(j=2*i;j<MAX;j=j+i)
        {
            C[j]=true;
        }
      }
    }
     
 }
*/
 
 
//////////////////////////////////////////////////////////D-S-U/////////////////////////////////////////////////////////
/*long long int parent[MAX];
long long int size[MAX];
void initialise()
{ 

    for(long  long int i=0;i<MAX;i++)
    {
        parent[i]=i;
        //cout<<i<<" ";
        size[i]=1;
    }
}
long long int  root(long long int x)
{
    while(x!=parent[x])
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}
 
    
void union1(long long int x,long long int y)
{
    if(size[x]>=size[y])
    {
        size[x]+=size[y];
        parent[y]=x;
        
    }
    else
    {
        size[y]+=size[x];
        parent[x]=y;
    }
}*/
//////////////////////////////////////////////////////MODPOWER//////////////////////////////////////////////////////////
 
 
long long int modulo(long long int a,long long  int b, long long int n){
    
    if(b==0)
        return 1;
    long long int  x=1, y=a%n; 
    
    
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
 
 
////////////////////////////////////////////////BIT/////////////////////////////////////////////////////////////////////
/* long long int bit[MAX+1]={0};
long long int query(long long int in,long long int n)
{
    //in=in+1;
    long long int sum=0;
    if(in==0)
        return 0;
    while(in>0)
    {
      sum=sum+bit[in];
        
        in=in-(in&(-in));
    }
    return sum;
}
void update(long long int in,long long int n,long long int val)
{
    // in=in+1;
    
    while(in<=n)
    {
       // cout<<in<<" ";
        bit[in]+=val;
        in=in+ (in &(-in));
    }
}
 
 */
 

////////////////////////////////////////////////DFS///////////////////////////////////////////////////////////////////
/*
  bool visited[MAX];
 long long int parent[MAX];
 long long int dist[MAX];


void dfs(vector<long long int>adj[],long long int i,long long int k)
{
    visited[i]=true;
    for(auto j:adj[i])
    {
        if(!visited[j])
        {
            dist[j]=dist[i]+1;
            parent[j]=i;
            dfs(adj,j,k);
            
        }
        
    }
}
 */
 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* find it hard to say the things I want to say the most
Find a little bit of steady as I get close
Find a balance in the middle of the chaos
Send me low, send me high, send me never demigod
I remember walking in the cold of November
Hoping that I make it to the end of December
Twenty-seven years and the end of my mind, but
Holding to the thought of another time, but
Looking to the ways of the ones before me
Looking for the path of the young and lonely
I don't want to hear about what to do
I don't want to do it just to do it for you
Hello, hello
Let me tell you what it's like to be a zero, zero
Let me show you what it's like to always feel, feel
Like I'm empty and there's nothing really real, real
I'm looking for a way out
Hello, hello
Let me tell you what it's like to be a zero, zero
Let me show you what it's like to never feel, feel
Like I'm good enough for anything that's real, real
I'm looking for a way out
I find it hard to tell you how I want to run away
I understand it always makes you feel a certain way
I find a balance in the middle of the chaos
Send me up, send me down, semi never demigod
I remember walking in the heat of the summer
Wide-eyed one with a mind full of wonder
Twenty-seven years and I've nothing to show
Falling from the doves to the dark of the crow
Looking to the ways of the ones before me
Looking for the path of the young and lonely
I don't want to hear about what to do, no
I don't want to do it just to do it for you
Hello, hello
Let me tell you what it's like to be a zero, zero
Let me show you what it's like to always feel, feel
Like I'm empty and there's nothing really real, real
I'm looking for a way out
Hello, hello
Let me tell you what it's like to be a zero, zero
Let me show you what it's like to never feel, feel
Like I'm good enough for anything that's real, real
I'm looking for a way out
Let me tell you 'bout it
Well let me tell you 'bout it
Maybe you're the same as me
Let me tell you 'bout it
Well let me tell you 'bout it
They say the truth will set you free
Hello, hello
Let me tell you what it's like to be a zero, zero
Let me show you what it's like to always feel, feel
Like I'm empty and there's nothing really real, real
I'm looking for a way out
Hello, hello
Let me tell you what it's like to be a zero, zero
Let me show you what it's like to never feel, feel
Like I'm good enough for anything that's real, real
I'm looking for a way out 
*/




void solve()
{
long long sum,d,i,w,j,k=0,l=0,r=0,m,n,p=0,cnt=0,cnt1=0,x,y=0,z=0,a,b,c,low,mid,high,ans=0,ans1=0,maxi=0,mini=INF,t1,x1,y1,z1,t,o;
string s,s1,s2,s3,s4;
  
     cin>>n>>x>>m;
     ans=x;
     l=x;
     k=x;
     map<long long int,long long int>ma;
     map<long long int,long long int>ma1;
    ma[x]=1;
    ma1[1]=x;
    for(i=2;i<=n;i++)
    {
        k=(k*k)%m;
        ma1[i]=k;
        if(ma[k]!=0)
        {
            l=ma[k];
            r=ma1[l];
            x=r;
            cnt=0;
            for(j=l;j<i;j++)
            {
                cnt+=r;
                r=(r*r)%m;
            }
            
            p=(n-i+1)/(i-l);
            ans=ans+p*cnt;
           
            l=(n-i+1)%(i-l);
            
            r=x;
            for(j=0;j<l;j++)
            {
                ans=ans+r;
                r=(r*r)%m;
            }
           cout<<ans<<endl;
            return;
        }
        ma[k]=i;
        ans+=k; 
    }
    
    cout<<ans<<endl;

    
}
int main()
{
    fastio();
    long long int t=1;
   //cin>>t;
    while(t--)
    {
        solve();
       
    }  
}
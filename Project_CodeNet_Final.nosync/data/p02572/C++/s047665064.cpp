#include<iostream> 
#include<vector> 
#include<algorithm> 
#include<iomanip> 
#include<stack> 
#include<unordered_map>
#include<queue> 
#include<deque>
#include<map> 
#include<climits>
#include<set> 
#include<string> 
//#include<time.h>
//#include<bits/stdc++.h> 
using namespace std; 
#define lld long long int 
#define eb emplace_back
//to insert pair use eb
#define mp make_pair
#define fi first
#define se second
#define pb push_back

#define X 1000000007
#define Y 998244353
#define E4 10000
#define E5 100000
#define E6 1000000
#define inf 2001001001001001001
#define pi 3.1415926535

# define rec2(i,a,n) for(lld i=a;i<n;i++) 
#define rec(i,n) for(lld i=0;i<n;i++)
#define rev(i,a,n) for(lld i=n-1;i>=a;i--)
#define all(v) (v).begin(), (v).end()
#define large(v)  *max_element(all(v))
#define small(v)  *min_element(all(v)) 
#define v vector 
#define p(x,y)  pair<x,y> 
const double EPS = 1e-6;

void google(int i)
{  cout<<"Case #"<<i<<": "; }

//prime sieve if needed 
//prime factors of number
lld prime[E6+1]; 
void sieve(lld n) 
{ rec(i,n+1) 
    prime[i]=1; 
   for(lld i=2;i*i<=n;i++) 
     { if(prime[i]!=1) 
          continue; 
         for(lld j=i*i;j<=n;j=j+i) 
          if(prime[i]==1)
           prime[j]=i; 
      }
}

lld gcd(lld a,lld b)
{
    if(a==0)
     return b; 
    return gcd(b%a,a); 
}

//fermat a^(m-2)%mod
lld binarymul(lld a,lld n,lld m)
{  lld res=1; 
 while(n) 
  { if(n%2) 
      { res=(res*a)%m; 
         n--; 
      } 
     a=(a*a)%m; 
     n/=2; 
  }
  return res; 
}
/*
void complexity(time_t end,time_t start)
{ 
  double taken = double(end - start); 
    cout<<"Time : "; 
    cout<<fixed<<taken<<setprecision(8);         cout<<" sec "<<endl;
}
*/ 
void bfs(lld s,v<lld> g[],lld n)
{ 
   bool vis[n]; 
   rec(i,n) 
    vis[i]=false; 
    
   vis[s]=true; 
   deque<lld> q; 
   q.pb(s); 
   
   while(!q.empty()) 
   {  
      s=q.front(); 
     q.pop_front(); 
      
     for(lld i=0;i<g[s].size();i++) 
      {  
        if(!vis[g[s][i]])
         { vis[g[s][i]]=true; 
            q.pb(g[s][i]); 
         }
      }
   }
}

void dfs(lld u,v<lld> g[],bool *vis)
{ 

   vis[u]=true; 
   for(lld i=0;i<g[u].size();i++) 
     if(!vis[g[u][i]])
          dfs(g[u][i],g,vis); 
       
}
void contest(lld t); 
int main()
{   
    /*
    time_t start, end; 
    time(&start); 
    */
   ios_base::sync_with_stdio(false); 
   cin.tie(0);
     #ifdef PUNEET_GOEL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
   //sieve(E6); 
    lld T=1; 
   // cin>>T;
    rec(t,T) 
    {
      contest(t); 
    }
    /*
     time(&end); 
    complexity(end,start);
    */
	return 0;
}

void contest(lld t)
{ 
  lld n,ans=0; 
  cin>>n; 
  lld a[n],b[n]; 
  
   rec(i,n)
  cin>>a[i]; 
  
  b[0]=a[0];
   for(lld i=1;i<n;i++) 
   b[i]=b[i-1]+a[i]; 
 
  rec(i,n) 
  { 
    lld x=(b[n-1]-b[i]+X)%X; 
      x=(a[i]*x)%X; 
    ans+=x ;  
    ans%=X; 
  } 
  cout<<ans<<endl; 
}
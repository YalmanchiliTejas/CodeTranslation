#include<bits/stdc++.h>
using namespace std;
#define tezi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(c) c.begin(),c.end()
#define ll long long
#define ull unsigned long long
#define traverse(c,it) for(auto it=c.begin();it!=c.end();it++)
#define lowerb(v,a) lower_bound(v.begin(),v.end(),a)
#define lowerbarr(v,n,a) lower_bound(v,v+n,a)
#define upperb(v,a) upper_bound(v.begin(),v.end(),a)
#define upperbarr(v,n,a) upper_bound(v,v+n,a)
#define maxval(v) max_element(v.begin(),v.end())
#define maxarr(v,n) max_element(v,v+n)
#define minval(v) min_element(v.begin(),v.end())
#define minarr(v,n) min_element(v,v+n)
#define sz(a) (ll)a.size()
#define f first
#define s second
#define PI 3.1415926536
#define mem0(v) memset(v,0,sizeof(v))
#define memf(v) memset(v,false,sizeof(v))
#define memt(v) memset(v,true,sizeof(v))
#define mem(v,a) memset(v,a,sizeof(v))
#define npos string::npos
#define inf 1e10;
#define MAX 1000000
#define MOD 1000000007
                   /**************SIEVE****************/

/*bool prime[MAX+1];
vector<ll> v;
void sieve(){ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true.
   
    memset(prime, true, sizeof(prime)); 
  
    for (long p=2; p*p<=MAX; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (long i=p*p; i<=MAX; i += p) 
                prime[i] = false; 
        } 
    } 
  for(int i=0;i<=MAX;i++)if(prime[i])v.pb(i);
  
   
    
   
} 
 
                                        /**************gcd****************/

ll gcd(ll a,ll b) 
{ if(a>b)swap(a,b);
    if (a == 0) 
        return b; 
 return gcd(b%a, a); 
}
 
 
 
                                         /**************POWER****************/
 ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2)%MOD;
    if (b % 2)
        return ((ull)res * (ull)res * (ull)a)%MOD;
    else
        return ((ull)res * (ull)res)%MOD;
}
   

 
 
 
 
                                     /**************MAIn****************/



int main()
{   
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("put.txt","w",stdout);
  #endif
  int T=1;
  //cin>>T;
  
  while(T--)
  {ll  n,x,m;
    cin>>n>>x>>m;
    int vis[m];
    for(int i=0;i<m;i++)vis[i]=-1;
    vector<ll> v;
    v.pb(x);vis[x]=0;ll ans=0;
    for(int i=1;i<=n;i++)
    {ll t;
      if(i==1)t=x;
      else
       t=v[v.size()-1]-v[v.size()-2];
      ll curr=(t*t)%m;
      if(vis[curr]!=-1)
      {//cout<<i<<' '<<curr<<endl;
        auto index=vis[curr];

        ll sum=v[v.size()-1];

        if(index!=0)sum-=v[index-1];

    
        ll cnt=i-index;

        
        ans+=(n-i)/cnt*sum;
        //cout<<ans<<endl;
   
        ll r=(n-i)%cnt;

         if(r)
         {ans+=v[index+r-1];
          if(index!=0)ans-=v[index-1];

         }  
          ans+=v[i-1];
        cout<<ans;return 0;


      }
      else
      {
        vis[curr]=i;v.pb(curr+v[v.size()-1]);
      }

    }
    cout<<v[n-1];
  

    

  

  }    


  
  
      cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

    

  
 
    
  

   
 
 
 
 
 
  
 
 


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
#define F first
#define S second
#define PI 3.1415926536
#define mem0(v) memset(v,0,sizeof(v))
#define memf(v) memset(v,false,sizeof(v))
#define memt(v) memset(v,true,sizeof(v))
#define mem(v,a) memset(v,a,sizeof(v))
#define npos string::npos
#define MAX 10000000
#define MOD 1000000009
                    /**************SIEVE****************/

/*bool prime[MAX+1];
vector<int> v;
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
ll cnt;
ll gcd(ll a,ll b) 
{ if(a>b)swap(a,b);
    if (a == 0) 
        return b; 
   cnt+=b/a; return gcd(b%a, a); 
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

ll a[3000];
ll dp[3000][3000];
ll func(int left,int right)
{ 


 if(left>right)return 0;
  if(dp[left][right]!=-1)return dp[left][right];
  if(left==right)return a[left];

  ll temp1=a[left]-func(left+1,right);
  ll temp2=a[right]-func(left,right-1);
  
  return dp[left][right]=max(temp1,temp2);
}




int main()
{   tezi
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("put.txt","w",stdout);
  #endif

  int T=1;
  //cin>>T;
  
  
  while(T--)
  {int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)dp[i][j]=-1;
    }
    loop(i,0,n)cin>>a[i];
    cout<<func(0,n-1);





    

  }
  
  
   
    
    
    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    

}
  
   




   
   

    
 
   
  

 
   
 
 
 
 
 
  
 
 
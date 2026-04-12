#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define vpll vector<pll>
#define vll vector<lli>
#define eps 0.000001
#define endl '\n'
 
using namespace std ;
 
#define MAXN 30001
//lli spf[MAXN];  
//void sieve();
//set<lli> factors(lli x);
//void getZarr(string str, lli Z[]);
lli power(lli x,lli y,lli p);

lli dp[3001][3001][2];
lli a[3001];

lli f(lli l,lli r,lli n)
{
    if(dp[l][r][n]!=-1)
        return dp[l][r][n];

    if(l == r && n==0)
        return dp[l][r][0]=a[l];

    else if(l == r && n==1)
        return dp[l][r][1]=0;

    if(n==0)
        return dp[l][r][0] = max(a[l]+f(l+1,r,1),a[r]+f(l,r-1,1));

    else
        return dp[l][r][1] = min(f(l+1,r,0),f(l,r-1,0));        

}


int main()
{  
/////////////////////////////////////
    
    fastio;
    
 
/////////////////////////////////////
    
    loopl(i,0,3001)
    loopl(j,0,3001)
        dp[i][j][0]=dp[i][j][1]=-1;
    

    lli n;
    cin>>n;


    lli sum=0;
    loopl(i,1,n+1)
    {
        cin>>a[i];
        sum+=a[i];
    }

    lli x = f(1,n,0);

    cout<<2*x - sum <<endl;






}
        
 
 
        
 
 
 
 /*   void sieve() 
    { 
        spf[1] = 1; 
        loopl(i,2,MAXN) 
            spf[i] = i; 
        for (lli i=4; i<MAXN; i+=2) 
            spf[i] = 2; 
      
        for (lli i=3; i*i<MAXN; i++) { 
            if (spf[i] == i) { 
                for (lli j=i*i; j<MAXN; j+=i) 
                    if (spf[j]==j) 
                        spf[j] = i; 
            } 
        }
 
    }*/ 
    /*
    multiset<lli> factors(lli x) 
    { 
        multiset<lli> pr; 
        while (x != 1) 
        { 
            pr.insert(spf[x]); 
            x = x / spf[x]; 
        } 
        return pr; 
    }
 
    */
 
    /*
    void dfs(lli q,lli root) 
    {
        vis[q]=1;
        
        ans[q]=1;
        for(auto x: v[q])
        {
            if(!vis[x])
            {
                if(a[x]==a[root] && x<root) continue;
                if(a[x]<a[root] || a[x]>a[root]+d) continue;
                dfs(x,root);
                ans[q]=(ans[q]*((ans[x]+1)%mod))%mod ;
            }
        }
            
    }
    */
 
 
 
    /*void getZarr(string str, lli Z[])
    {
        lli n = str.length();
        lli L, R, k;
        L = R = 0;
        for (lli i = 1; i < n; ++i){
            if (i > R){
                L = R = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            } else {
                k = i-L;
                if (Z[k] < R-i+1)
                    Z[i] = Z[k];
                else {
                    L = i;
                    while (R<n && str[R-L] == str[R])
                        R++;
                    Z[i] = R-L;
                    R--;
                }
            }
        }
    }
 
    */
 
    
   lli power(lli x, lli y, lli p) 
    { 
        lli res = 1;   
        x = x % p;  
        while (y > 0) 
        { 
            if (y & 1) 
                res = (res*x) % p; 
      
            y = y>>1;  
            x = (x*x) % p;   
        } 
        return res; 
    } 
    
 
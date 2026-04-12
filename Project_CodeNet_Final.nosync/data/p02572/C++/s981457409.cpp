//Ardhendu Reja ,Jalpaiguri Government Engineering College 
#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define PP pair<int,pair<int,int>>
#define P pair<int,int>
#define mod 1000000007
#define sp fixed<<setprecision(9)
using namespace std; 

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
} 



void solve(int t){
    int n,k;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //a[0]=0;
    int suff[n+2];
    suff[n+1]=0;
    for(int i=n;i>=1;i--){
        suff[i]=(a[i]+suff[i+1])%mod;
    }
    int ans=0;
    for(int i=1;i<=n-1;i++){
        ans+=(a[i]*suff[i+1])%mod;
        ans%=mod;
    }
    cout<<ans<<'\n';

}



int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    //double    pi=3.14159265358979323846;
    //sieve();
    //precompute();
    int test_case=1;
    //cin>>test_case;
    int t=1;
    while(test_case--){
        solve(t);
        t++;
    }
    
    return 0;
    
}//Ardhendu Reja ,Jalpaiguri Government Engineering College 

/*const int N=300005;
const int LOGN=25;

int h[N];
int p[N][LOGN];
//int val[N][LOGN];
vector<int> adj[N];

int lca(int u,int v){
    if(h[u]<h[v]){
        swap(u,v);//for sure h[u]>=h[v]
    }
    //step 1-kill the difference and make them same height
    int diff=h[u]-h[v];
    for(int i=0;i<LOGN;i++){
        if((diff&(1<<i))){
            //if the diff has i^th bit on
            u=p[u][i];
        }
    }
    //conjecture here is that u and v has same height
    if(u==v) return u;
    //make the jump if the ancestors mismatch
    //step 2-at same height start jumping from higher power of 2 to lower power of 2
    for(int i=LOGN-1;i>=0;i--){
        if(p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    //we will be one step away from the lca
    return p[u][0];
}


void dfs(int node,int par){
    h[node]=h[par]+1;
    p[node][0]=par;
    //val[node][0]=A[node];
    for(auto x:adj[node]){
        if(x!=par){
            dfs(x,node);
        }
    }
}

dfs(1,0);
    for(int i=0;i<LOGN;i++){
        //val[0][i]=0;
        p[0][i]=0;
    }
    for(int i=1;i<LOGN;i++){
        for(int u=1;u<=n;u++){
            p[u][i]=p[p[u][i-1]][i-1];
        }
    }

*/

/*
struct dsu {
    vector<int> par;
    vector<int> rnk;
    vector<int> sz;

    void init(int n){
        par.resize(n+1);
        rnk.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            rnk[i]=0;
            sz[i]=1;
        }
    }

   int findpar(int node ){
        if(node == par[node])
            return node;
        return par[node] = findpar(par[node]);
    }

    void unite(int u ,int v){
        int p1 = findpar(u);
        int p2 = findpar(v);
        if(p1!=p2)
        {
            int r1 = rnk[p1];
            int r2 = rnk[p2];
            if(r1 < r2)
            {
                par[p1] = p2;
                sz[p2]+=sz[p1];
                sz[p1]=0;
                rnk[p2]++;
            }
            else
            {
               par[p2] = p1;
               sz[p1]+=sz[p2];
               sz[p2]=0;
               rnk[p1]++;
            }
        }
    }

} G;
*/

/*const int N = 1000001;
int factorialNumInverse[N + 1]; 
  
// array to precompute inverse of 1! to N! 
int naturalNumInverse[N + 1]; 
  
// array to store factorial of first N numbers 
int fact[N + 1]; 
  
// Function to precompute inverse of numbers 
void InverseofNumber(int p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(int p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    // precompute inverse of natural numbers 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
// Function to calculate factorial of 1 to N 
void factorial(int p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
// Function to return nCr % p in O(1) time 
int Binomial(int N, int R, int p) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    int ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 
*/
/*int powmod(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}*/

/*long double cal_cos(long double n) 
{ 
    long double accuracy = 0.00001, x1, denominator, cosx, cosval; 
      
    // Converting degrees to radian 
    n = n * (3.142 / 180.0); 
      
    x1 = 1; 
      
    // maps the sum along the series 
    cosx = x1;          
      
    // holds the actual value of sin(n) 
    cosval = cos(n); 
    int i = 1; 
    do
    { 
        denominator = 2 * i * (2 * i - 1); 
        x1 = -x1 * n * n / denominator; 
        cosx = cosx + x1; 
        i = i + 1; 
    } while (accuracy <= fabs(cosval - cosx)); 
    return cosx; 
} 

long double cal_sin(long double n) 
{     
    long double accuracy = 0.00001, denominator, sinx, sinval; 
      
    // Converting degrees to radian 
    n = n * (3.142 / 180.0);  
  
    long double x1 = n; 
      
    // maps the sum along the series 
    sinx = n;          
      
    // holds the actual value of sin(n) 
    sinval = sin(n);     
    int i = 1; 
    do
    { 
        denominator = 2 * i * (2 * i + 1); 
        x1 = -x1 * n * n / denominator; 
        sinx = sinx + x1; 
        i = i + 1; 
    } while (accuracy <= fabs(sinval - sinx)); 
    return sinx; 
} 

long double dis(int x1,int y1,int x2,int y2){

    int ans=((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

    long double x=sqrtl((long double)ans);
    return x;
}*/
 
/*int fact[N], fact_inverse[N];

int powmod(int x, int n, int md){
    int ans=1;
    while(n){
        if(n&1)
            ans=(ans*x)%md;
        n/=2;
        x=(x*x)%md;
    }
    return ans;
}
 
int inverse_mod(int num){
    return powmod(num, mod-2, mod);
}
 
void precompute(){
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
    fact_inverse[N-1]=inverse_mod(fact[N-1]);
    for(int i=N-2;i>=0;i--){
        fact_inverse[i]=fact_inverse[i+1]*(i+1);
        fact_inverse[i]%=mod;
    }
}
 
int binomial(int x, int y){
    if(y>x)
        return 0;
    int num = fact[x];
    num *= fact_inverse[y];
    num %= mod;
    num *= fact_inverse[x-y];
    num %= mod;
    return num;
}*/
 
 /*class node{
public:
    node* left;
    node* right;
 };

class trie{
    node* root;
public:
    trie(){
        root=new node();
    }

    void insert(int n){
        node* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(bit==0){
                if(temp->left==NULL){
                    temp->left=new node();
                }
                temp=temp->left;
            }else{
                if(temp->right==NULL){
                    temp->right=new node();
                }
                temp=temp->right;
            }
        }
    }
    int max_xor(int value){
        node* temp=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(value>>i)&1;
            if(bit==0){
                if(temp->right!=NULL){
                    ans+=(1<<i);
                    temp=temp->right;
                }else{
                    temp=temp->left;
                }
            }else{
                if(temp->left!=NULL){
                    ans+=(1<<i);
                    temp=temp->left;
                }else{
                    temp=temp->right;
                }
            }
        }
        return ans;
    }

    vector<int> range_xor1(vector<int> arr,int n){
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=(pref[i-1]^arr[i]);
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            int val=arr[i];
            //cout<<val<<' ';
            insert(val);
            int curr=max_xor(val);
            mx=max(mx,curr);
            pref[i]=mx;
            //cout<<pref[i]<<'\n';
        }
        //cout<<'\n';
        return pref;
    }
    vector<int> range_xor2(vector<int> arr,int n){
        vector<int> suff(n+2,0);
        for(int i=n;i>=1;i--){
            suff[i]=(suff[i+1]^arr[i]);
        }
        int mx=0;
        for(int i=n;i>=1;i--){
            int val=arr[i];
            //cout<<val<<' ';
            insert(val);
            int curr=max_xor(val);
            mx=max(mx,curr);
            suff[i]=mx;
            //cout<<suff[i]<<'\n';
        }
        //cout<<'\n';
        return suff;
    }
};
*/
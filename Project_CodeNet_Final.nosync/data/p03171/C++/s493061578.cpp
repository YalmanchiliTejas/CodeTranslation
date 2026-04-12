#include<bits/stdc++.h>


//      DEEP


using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fwd(i,a,n) for(int i=a;i<n;i++)
#define bak(i,a,n) for(int i=a;i>=n;i--)
#define all(v) v.begin(),v.end()
#define pb push_back
#define endl '\n'
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pll;
typedef set<int> si;
const ll mod = 1e9 + 7;
const ll modl=998244353;
const double pie=3.1415926535;
                                                    //power
ull power(ull x,ull y){
   if(y==0) return 1;
   else{
     if(y%2==0) return power(x*x,y/2);
     else return x*power(x*x,(y-1)/2);
   }
}

                        //                    Modular Exponentiation

ll mod_power(ll x, ll y, ll m)
{
    ll r = 1;     // Initialize result

    x = x % m; // Update x if it is more than or equal to m

    if (x == 0) return 0; // In case x is divisible by m;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            r = (r*x) % m;

        // y must be even now
        y = y/2;
        x = (x*x) % m;
    }
    return r;
}

                                                      //GCD
ll gcd(ll x,ll y){
   if(y==0)return x;
   return gcd(y,x%y);
}
//                                         EXTENDED_EUCLID
vector<ll>extended_Euclid(ll a,ll b){
    vector<ll>v(3);
    if(b==0){
        v[0]=a;v[1]=1;v[2]=0;
        return v;
    }
    else{
         vector<ll>v1 = extended_Euclid(b,a%b);    //recursive call
         v[0]=v1[0];
         v[1]=v1[2];
         v[2]=v1[1]-(a/b)*v1[2];
         return v;
    }
}
                                          // DFS ( number of connected components  )
//vector<vector<ll> >adj(200001);
//bool visited[200001];
/*ll dfs(int x,int c){                         // x - > node      c - > number of edges in the component
    if(visited[x])return c;
    else{
        visited[x]=true;
        int y=c;
        for(int i=0;i<adj[x].size();i++){
            if(!visited[adj[x][i]]){
                c+=1;
                int d=dfs(adj[x][i],y);
                c+=d;
            }
        }
        return c;
    }
}
*/
                                              // SIEVE

/*
bool isPrime[100001];
void sieve(int N) {

        for(int i = 0; i <= N;++i) {
            isPrime[i]=true;
        }
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
    }
*/
                               // Binary Search
/*
ll bin_search(ll y){
  while(lo<hi){
    x=lo+(hi-lo)/2;
    if(condition){
            .....
    }
    else{
                  // increase lo or decrease hi suitably
            }
   }
}
*/

int main(){
    boost;
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--){
        int n;
        cin>>n;
        vll v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        vector<vector<ll> >dp(3005,vector<ll>(3005));
        //dp[0][n-1] is the answer to the problem
        for(int L=n-1;L>=0;L--){
          for(int R=L;R<n;R++){
            if(L==R)dp[L][R]=v[L];
            else{
              dp[L][R]=max(v[L] - dp[L+1][R],v[R] - dp[L][R-1]);
            }
          }
        }
        cout<<dp[0][n-1]<<endl;
    }

  }











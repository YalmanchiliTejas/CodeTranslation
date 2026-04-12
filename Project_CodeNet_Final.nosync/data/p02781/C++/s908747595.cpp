#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int uli;
typedef long double Lf;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define fastIO  std::ios::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define N 105
#define NN 25
#define SZ(x) ((lli) (x).size())
#define loop(i,s,n) for(int (i)=(s);(i)<(n);(i)++)
#define loopr(i,n,s) for(int (i)=(n)-1;(i)>=(s);(i)--)
#define pb push_back
#define o2(a,b) cout<<(a)<<" "<<(b)<<endl
#define o3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define o4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define cl cout<<endl
#define r0 return 0
#define x first
#define y second


inline lli modadd(lli n,lli m,lli p=mod){
    return ((n+m)%p+p)%p;
}

inline lli modsub(lli n,lli m,lli p=mod){
    return ((n-m+p)%p+p)%p;
}

inline lli modpro(lli n,lli m,lli p=mod){
    return (((n%p)*(m%p))%p+p)%p;
}

inline uli powe(lli x,lli y){
    uli res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

inline lli modpow(lli x,lli y,lli p=mod){
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x, p);
        y = y >> 1;
        x = modpro(x , x, p);
    }
    return res;
}

inline lli modInverse(lli n, lli p=mod)
{
    if(n==1) return 1;
    return modpow(n, p-2, p);
}

inline lli moddiv(lli n,lli m,lli p=mod){
    return modpro(n,modInverse(m,p),p);
}

inline lli modadd3(lli x, lli y, lli z,lli p=mod){
    return modadd(modadd(x,y,p),z,p);
}

inline lli modadd4(lli x, lli y, lli z, lli w,lli p=mod){
    return modadd(modadd(x,y,p),modadd(z,w,p),p);
}

template <typename T>
inline T max3(T x, T y, T z){
    return max(max(x,y),z);
}

template <typename T>
inline T max4(T x, T y, T z, T w){
    return max(max3(x,y,w),z);
}

template <typename T>
inline T min3(T x, T y, T z){
    return min(min(x,y),z);
}

template <typename T>
inline T min4(T x, T y, T z, T w){
    return min(min3(x,y,w),z);
}


template <typename T>
void printArr(T *arr, int s, int n){
    for(int i=s;i<=n;i++){

        cout<<arr[i]<<" ";
    }cout<<endl;
}

//template<class X, class Y, class Z>
//struct triple {
//    X x;
//    Y y;
//    Z z;
//
//     friend bool operator<(triple a, triple b)
//    {
//        if(a.x!=b.x) return a.x<b.x;
//        else if(a.y!=b.y) return a.y<b.y;
//        else return a.z<=b.z;
//    }
//};
//
//
//template<class X, class Y, class Z, class W>
//class quad {
//    public:
//    X x;
//    Y y;
//    Z z;
//    W w;
//
//     friend bool operator<(quad a, quad b)
//    {
//        if(a.x!=b.x) return a.x<b.x;
//        else if(a.y!=b.y) return a.y<b.y;
//        else if(a.z!=b.z)return a.z<b.z;
//        else return a.w<b.w;
//    }
//};


//template <typename T>
//T gcd(T a, T b)
//{
//    if (a == 0)
//        return b;
//    if(b==0)
//        return a;
//    T t;
//    while((a>0)&&(b>0)){
//     t = a;
//     a=b%a;
//     b=t;
// }
//
// return max(a,b);
//}



//
//uli choose(uli n, uli k){
//uli res = 1;
//
//    // Since C(n, k) = C(n, n-k)
//    if ( k > n - k )
//        k = n - k;
//
//    // Calculate value of
//    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
//    for (uli i = 0; i < k; ++i)
//    {
//        res *= (n - i);
//        res /= (i + 1);
//    }
//
//    return res;
//}
//

//
//vector<vector<int>> adj;
////vector<bool> visited;
//vector<int> pa;
////queue<int> q;
//
//class Graph{
//
// public:
//    int V;
//
//
//
//    Graph(int V)
//{
//    this->V = V;
//
//    adj.resize(V);
//    pa.resize(V);
//}
//
//void addEdge(int a, int b)
//{
//    adj[a].pb(b);
//    adj[b].pb(a);
//}
//
////void dfs(int x){
////    visited[x]=1;
////    v.pb(x);
////    v2.pb(a[x]);
////    for(auto u: adj[x]){
////        if(visited[u]) continue;
////        dfs(u);
////    }
////}
//
//
//
//
//
//void dfsTree(int x, int p){
//
//    pa[x]=p;
//    for(auto u: adj[x]){
//        if(u==p) {continue;}
//        dfsTree(u,x);
//    }
//
//}
//
//
//
////void bfs(int x){
////    visited[x]=1;
////    q.push(x);
////    dist[x]=0;
////    v.pb(x);
////    while(!q.empty()){
////        int s = q.front();
////        q.pop();
////        for(int u : adj[s]){
////            if(visited[u]==1) continue;
////            visited[u]=1;
////            dist[u]=dist[s]+1;
////            v.pb(u);
////            //cout<<u<<endl;
////            q.push(u);
////        }
////    }
////}
//
////int connectedcomponents(int n){
////    int ans=0;
////    loop(i,1,n+1){
////        if(!visited[i]){
////            ans++;
////            dfs(i);
////        }
////
////    }
////    return ans;
////}
//
//};


//template <typename T>
//T findpowerfactorial(T n,T p)
//{
//    T x = 0;
//    while (n)
//    {
//        n /= p;
//        x += n;
//    }
//    return x;
//}
//
//template <typename T>
//int getibit(T n, int i){
//    //cout<<(n&(1LL<<i))<<endl;
//    return (n&(1LL<<i))?1:0;
//}
//
//template <typename T>
//int findbits(T n, T p){
//    int x=0;
//    while(n>0){
//        n/=p;
//        x++;
//    }
//    return x;
//}
//
//
////
//vector<pair<lli,int>> v;
//void primeFactors(lli n)
//{
//
//    int c=0;
//    while (n % 2 == 0)
//    {
//        n = n/2;
//        c++;
//    }
//    if(c>0) v.pb({2,c});
//
//
//    for (lli i = 3; i*i <= n; i = i + 2)
//    {   c=0;
//        //if(n%i==0) {v.pb(i);}
//        while (n % i == 0)
//        {
//            n = n/i;
//            c++;
//        }
//        if(c>0)v.pb({i,c});
//
//    }
//    if (n > 2)
//        v.pb({n,1});
//}




//int nCrModPFermat(int n, int r, lli p)
//{
//   // Base case
//   if (r==0)
//      return 1;
//
//
//    return (fac[n]* modInverse(fac[r], p) % p *
//            modInverse(fac[n-r], p) % p) % p;
//}


/*BITMASK
for( int inum = 0 ; inum < ( 1 << n ) ; ++ inum ) {
     for ( int pos = 0; pos < n ; ++pos ) {
         if (  inum & ( 1 << pos )  ){
              results[inum] += s [pos] ; //DO SOMETHING
         }
     }
}
*/
int a[N];
int len;
int k;
lli dp[N][4][2];
lli fu(int pos, int hmz, int f){
    if(pos==len){
        if(hmz==k) return 1;
        else return 0;
    }
    if(hmz>3) return 0;
    if(dp[pos][hmz][f]!=-1) return dp[pos][hmz][f];

    int lm=a[pos];
    if(f==1) lm = 9;

    lli ans=0;
    int nf;

    loop(i,0,lm+1){
        nf=f; if(f==0&&i<lm) nf=1;
        if(i==0)
        ans+=(fu(pos+1,hmz,nf));
        else ans+=(fu(pos+1,hmz+1,nf));
    }

    return dp[pos][hmz][f] = ans;
}

int main(){
    fastIO;
    int erer=1;
    //cin>>erer;
    loop(erer2,1,erer+1){
        string s;
        cin>>s;
        loop(i,0,SZ(s)) a[i]=(int)(s[i]-'0');
        len = SZ(s);
        memset(dp,-1,sizeof(dp));
        cin>>k;

        cout<<fu(0,0,0)<<endl;



    }
    return 0;
}

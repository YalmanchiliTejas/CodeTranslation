#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
// #define mp make_pair
#define pq priority_queue
// const int128_t mod=1000000007;
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)
#define ll long long
using namespace boost::multiprecision;
using namespace std;
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


const int N=1000005;
ll fact[N],invfact[N];
int128_t power(int128_t x,int128_t y, int128_t mod){
  if(y<=0) return 1LL;
  int128_t z=power(x,y/2,mod);
  if(y%2) return (((z*z)%mod)*x)%mod;
  return (z*z)%mod;
}
//
// void pre(){
//   fact[0]=invfact[0]=invfact[1]=fact[1]=1;
//   rep(i,2,N) fact[i]=(i*fact[i-1])%mod;
//   rep(i,2,N) invfact[i]=(invfact[i-1]*power(i,mod-2))%mod;
// }
// ll nCr(ll n,ll k){ return (((fact[n]*invfact[n-k])%mod)*invfact[k])%mod; }
//
//
//
// const int N1=1e6+1;
// vector<int> isprime(N1,1),prime;
// void seive(){
//   rep(i,2,sqrt(N1)+1){
//       if(isprime[i]){
//         for(int j=i*i;j<N1;j+=i) isprime[j]=0;
//         prime.pb(i);
//       }
//   }
//   rep(i,sqrt(N1)+1,N1) if(isprime[i]) prime.pb(i);
// }
//
//
//
// struct dsu {
//     vector<int> par, rank;
//     dsu(int n): par(n+1), rank(n+1) {
//         for (int i = 0; i <= n; i++) {
//             par[i] = i;
//             rank[i]= 1;
//         }
//     }
//     int root(int a) {
//         if (a == par[a]) return a;
//         return par[a] = root(par[a]);
//     }
//     void merge(int a, int b) {
//         a = root(a);
//         b = root(b);
//         if (a == b) return;
//         if (rank[a] > rank[b]) swap(a, b);
//         par[b] = a;
//     }
//     set<int> parent(int n){
//         set<int> s;
//         for(int i=1;i<=n;i++){
//             s.insert(root(i));
//         }
//         return s;
//     }
// };

void solve(){
  // int n,k;
  // cin>>n>>k;
  // // ll ans=0;
  // // rep(i,1,n/k+1){
  // //   int left=n-i*k;
  // //
  // //   ans=(ans+nCr(left+i-1,i-1))%mod;
  // // }
  // ll dp[n][k];
  // rep(i,0,n) rep(j,0,i+1) dp[i][j]=
  // cout<<ans<<endl;

  ull n,x,m;
  cin>>n>>x>>m;
  ull z=x,last=x;
  map<ull,ull> m1;
  vector<ull> v1;
  v1.push_back(last);
  m1[last]=0;
  int idx=-1,idx2=-1;
  rep(i,1,n){
    last=(last*last)%m;
    z=z+last;
    if(last==0) break;
    if(n>10000000 && m1.find(last)!=m1.end()){
      idx=m1[last];
      idx2=i;
      break;
    }
    else{
      m1[last]=i;
      v1.push_back(last);
    }
  }
  if(idx2!=-1 ){
    ull cycle_sum=accumulate(v1.begin()+idx,v1.end(),0LL);
    ull ans=accumulate(v1.begin(),v1.end(),0LL);
    ull len=v1.size()-idx;
    ull l=n-idx2;
    ull num=l/len,num2=l%len;
    ans=ans+cycle_sum*num+accumulate(v1.begin()+idx,v1.begin()+idx+num2,0LL);
    cout<<ans<<endl;
  }
  else cout<<z<<endl;
}

int main(){
    optimizeIO();
    int r=1;
    // pre();
    {solve();}
}

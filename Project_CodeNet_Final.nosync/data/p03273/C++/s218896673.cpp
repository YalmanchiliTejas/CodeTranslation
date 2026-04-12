#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
/////////////////// TYPES & MACROS ///////////////////////////////
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define vv vector
#define exist(s,e) (s.find(e)!=s.end())
using ll=long long int; using dd=double;
using pii=pair<int,int>; using pll=pair<ll,ll>;
typedef vector<int> vi;
ll INFLL=(ll)2e18, MOD=1'000'000'007;
const int INF=0x3f3fffff ;
/////////////////// DEBUG /////////////////////////////////////////
#define D(x) cerr<<#x<<" is: "<<x<<'\n';
#define DD(x,y) cerr<<"("<<#x<<","<<#y<<") are: "<<x<<" "<<y<<'\n';
/////////////////// VARIABLES & FUNCTIONS//////////////////////////
vv<vi> adj; vv<vv<int>> vis;
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1},dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};
inline ll mexp(ll x,ll n,ll m){ll res=1;while(n){if(n&1)res=(res*x)%m;n>>=1;x=((x%m)*(x%m))%m;}return res;}
inline bool ispow2(ll x){ return x && (!(x&(x-1)));}
inline ll gcd(ll x, ll y){ pll p{x,y}; while(p.ss) p={p.ss,p.ff%p.ss}; return p.ff;}


/////////////////// MAIN STARTS //////////////////////////////////
int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
cout<<fixed;cerr<<fixed; cout<<setprecision(10); cerr<<setprecision(3);
// random_device rd; mt19937 genr(rd());

#ifdef DEBUG
  auto tStart = chrono::system_clock::now(); //freopen("op.txt","w",stdout);
#endif

int r,c; cin>>r>>c;
char mat[r][c];
for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>mat[i][j];
bool dr[r], dc[c];
memset(dr,0,sizeof(dr));
memset(dc, 0, sizeof(dc));
for(int i=0;i<r;i++){
  int ct=0;
  for(int j=0;j<c;j++) if(mat[i][j]=='.') ++ct;
  if(ct==c) dr[i]=true;
}
for(int j=0;j<c;j++){
  int ct=0;
  for(int i=0;i<r;i++){
    if(mat[i][j]=='.') ++ct;
  }
  if(ct==r) dc[j]=true;
}
for(int i=0;i<r;i++){
  if(dr[i]) continue;
  for(int j=0;j<c;j++){
    if(dc[j]) continue;
    else cout<<mat[i][j];
  }
  cout<<endl;
}

#ifdef DEBUG
  auto diff=chrono::system_clock::now()-tStart;
  cerr<<"\nExecution time: "<<chrono::duration<dd,milli>(diff).count()<<" ms.\n";
#endif
return 0;
}
